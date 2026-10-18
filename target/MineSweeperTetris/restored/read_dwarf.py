import sys, struct, inspect, io, json, hashlib, collections
import ntpath
from pathlib import Path
ROOT = Path(__file__).resolve().parent
REPO = ROOT.parents[2]
sys.path.insert(0, str(REPO / 'tools/python'))
from elftools.dwarf.dwarfinfo import DWARFInfo, DwarfConfig, DebugSectionDescriptor

def pe_dwarf(path):
    b = path.read_bytes()
    pe = struct.unpack_from('<I', b, 60)[0]
    count = struct.unpack_from('<H', b, pe + 6)[0]
    sym, nsym = struct.unpack_from('<II', b, pe + 12)
    strings = sym + nsym * 18
    off = pe + 24 + struct.unpack_from('<H', b, pe + 20)[0]
    sec = {}
    for i in range(count):
        h = off + i * 40
        name = b[h:h+8].rstrip(b'\0').decode()
        if name.startswith('/'):
            start = strings + int(name[1:])
            name = b[start:b.index(0, start)].decode()
        vs, va, size, pos = struct.unpack_from('<IIII', b, h+8)
        sec[name] = DebugSectionDescriptor(io.BytesIO(b[pos:pos+size]), name, pos, vs, va)
    kw = {k: sec.get('.'+k[:-4]) for k in inspect.signature(DWARFInfo).parameters if k!='config'}
    return DWARFInfo(config=DwarfConfig(True, 'x86', 4), **kw), sec

def text(value):
    return value.decode('utf-8', 'replace') if isinstance(value, bytes) else value

def attr(die, key):
    if key in die.attributes: return die.attributes[key]
    for ref in ('DW_AT_specification','DW_AT_abstract_origin'):
        if ref in die.attributes:
            v = attr(die.get_DIE_from_attribute(ref), key)
            if v: return v

def val(die, key, default=None):
    a=attr(die,key)
    return text(a.value) if a else default

def typeref(die):
    if 'DW_AT_type' in die.attributes: return die.get_DIE_from_attribute('DW_AT_type')
    for ref in ('DW_AT_specification','DW_AT_abstract_origin'):
        if ref in die.attributes: return typeref(die.get_DIE_from_attribute(ref))

def type_name(die, depth=0):
    if die is None: return 'void'
    if depth>20: return '/*recursive*/'
    tag=die.tag
    name=val(die,'DW_AT_name')
    if name and tag not in ('DW_TAG_const_type','DW_TAG_volatile_type'): return name
    t=type_name(typeref(die),depth+1)
    if tag=='DW_TAG_pointer_type': return t+' *'
    if tag=='DW_TAG_reference_type': return t+' &'
    if tag=='DW_TAG_const_type': return 'const '+t
    if tag=='DW_TAG_volatile_type': return 'volatile '+t
    if tag=='DW_TAG_array_type':
        dims=[]
        for c in die.iter_children():
            if c.tag=='DW_TAG_subrange_type':
                up=val(c,'DW_AT_upper_bound')
                dims.append('['+str(up+1 if isinstance(up,int) else '')+']')
        return t+''.join(dims)
    if tag=='DW_TAG_subroutine_type': return t+' (/*function pointer signature*/ )'
    return '/*'+tag+'*/ '+t

def declaration(die, name, depth=0):
    if die is None: return 'void '+name
    if depth>25: return '/* recursive type */ '+name
    tag=die.tag
    n=val(die,'DW_AT_name')
    if n and tag not in ('DW_TAG_const_type','DW_TAG_volatile_type'):
        return n+' '+name
    target=typeref(die)
    if tag in ('DW_TAG_pointer_type','DW_TAG_reference_type'):
        mark='*' if tag=='DW_TAG_pointer_type' else '&'
        wrapped=mark+name
        if target and target.tag in ('DW_TAG_array_type','DW_TAG_subroutine_type'): wrapped='('+wrapped+')'
        return declaration(target,wrapped,depth+1)
    if tag in ('DW_TAG_const_type','DW_TAG_volatile_type'):
        qual='const' if tag=='DW_TAG_const_type' else 'volatile'
        # GCC can qualify the reference carrier in DWARF. This does not make
        # the referenced object const; C++ ignores cv-qualification of references.
        if target and target.tag=='DW_TAG_reference_type':
            return declaration(target,name,depth+1)
        if target and target.tag=='DW_TAG_pointer_type':
            return declaration(typeref(target),'*'+qual+' '+name,depth+1)
        return qual+' '+declaration(target,name,depth+1)
    if tag=='DW_TAG_array_type':
        suffix=''
        for c in die.iter_children():
            if c.tag=='DW_TAG_subrange_type':
                up=val(c,'DW_AT_upper_bound')
                suffix+='['+str(up+1 if isinstance(up,int) else '')+']'
        return declaration(target,name+suffix,depth+1)
    if tag=='DW_TAG_subroutine_type':
        args=[declaration(typeref(c),val(c,'DW_AT_name',''),depth+1) for c in die.iter_children() if c.tag=='DW_TAG_formal_parameter']
        return declaration(target,name+'('+', '.join(args)+')',depth+1)
    return type_name(die)+' '+name

all_stats=[]
for path in sorted(ROOT.parent.glob('*.exe')):
    dw, sections=pe_dwarf(path)
    if '.debug_info' not in sections:
        all_stats.append({'exe':path.name,'dwarf':False,'debug_bytes':0})
        continue
    records=[]; types=[]; globals_=[]; counts=collections.Counter(); cus=[]
    for cu in dw.iter_CUs():
        top=cu.get_top_DIE(); source=val(top,'DW_AT_name'); cus.append(source)
        lp=dw.line_program_for_CU(cu)
        def source_file(d):
            idx=val(d,'DW_AT_decl_file')
            if idx and lp and idx<=len(lp['file_entry']):
                return ntpath.basename(text(lp['file_entry'][idx-1].name))
            return ntpath.basename(source)
        def local_children(d):
            for c in d.iter_children():
                if c.tag=='DW_TAG_variable': yield c
                elif c.tag=='DW_TAG_lexical_block': yield from local_children(c)
        for d in cu.iter_DIEs():
            counts[d.tag]+=1
            if d.tag=='DW_TAG_subprogram' and val(d,'DW_AT_low_pc'):
                children=list(d.iter_children())
                params=[{'name':val(c,'DW_AT_name'),'type':type_name(typeref(c)), 'declaration':declaration(typeref(c),val(c,'DW_AT_name','')), 'artificial':bool(val(c,'DW_AT_artificial',False))} for c in children if c.tag=='DW_TAG_formal_parameter']
                locals_=[{'name':val(c,'DW_AT_name'),'type':type_name(typeref(c)),'declaration':declaration(typeref(c),val(c,'DW_AT_name','')),'line':val(c,'DW_AT_decl_line')} for c in local_children(d)]
                records.append({'address':val(d,'DW_AT_low_pc'),'name':val(d,'DW_AT_name'), 'linkage':val(d,'DW_AT_linkage_name',val(d,'DW_AT_MIPS_linkage_name')),'unit':source,'source':source_file(d),'line':val(d,'DW_AT_decl_line'),'return_type':type_name(typeref(d)),'parameters':params,'locals':locals_})
            if d.tag in ('DW_TAG_structure_type','DW_TAG_class_type','DW_TAG_enumeration_type') and val(d,'DW_AT_byte_size'):
                members=[];bases=[];enums=[]
                for c in d.iter_children():
                    if c.tag=='DW_TAG_member': members.append({'name':val(c,'DW_AT_name'),'type':type_name(typeref(c)),'declaration':declaration(typeref(c),val(c,'DW_AT_name','')),'offset':val(c,'DW_AT_data_member_location'),'line':val(c,'DW_AT_decl_line'),'constant':val(c,'DW_AT_const_value'),'external':bool(val(c,'DW_AT_external',False))})
                    elif c.tag=='DW_TAG_inheritance': bases.append(type_name(typeref(c)))
                    elif c.tag=='DW_TAG_enumerator': enums.append({'name':val(c,'DW_AT_name'),'value':val(c,'DW_AT_const_value')})
                types.append({'name':val(d,'DW_AT_name'),'size':val(d,'DW_AT_byte_size'),'source':source_file(d),'unit':source,'tag':d.tag,'members':members,'bases':bases,'enumerators':enums})
            if d.tag=='DW_TAG_variable' and d.get_parent() and d.get_parent().tag=='DW_TAG_compile_unit':
                globals_.append({'name':val(d,'DW_AT_name'),'type':type_name(typeref(d)),'declaration':declaration(typeref(d),val(d,'DW_AT_name','')),'source':source_file(d),'unit':source,'line':val(d,'DW_AT_decl_line'),'constant':val(d,'DW_AT_const_value')})
    stat={'exe':path.name,'sha256':hashlib.sha256(path.read_bytes()).hexdigest(),'dwarf':True,'debug_bytes':sum(s.size for n,s in sections.items() if n.startswith('.debug')),'tags':dict(counts),'compile_units':cus,'defined_functions':len(records),'recovered_local_records':sum(len(r['locals']) for r in records)}
    (ROOT/(path.stem+'.dwarf.json')).write_text(json.dumps({'stats':stat,'functions':records,'types':types,'globals':globals_},ensure_ascii=False,indent=2),encoding='utf-8')
    all_stats.append(stat)
(ROOT/'debug_comparison.json').write_text(json.dumps(all_stats,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps([{k:v for k,v in s.items() if k not in ('tags','compile_units')} for s in all_stats],indent=2))
