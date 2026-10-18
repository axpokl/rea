import idaapi,idc,idautils,json,re,os,struct
idaapi.auto_wait()
root=r'G:\Program Files\REA\target\MineSweeperTetris\restored'
code=open(os.path.join(root,'improved_raw.cpp')).read()
names=sorted(set(re.findall(r'\b(?:off|unk|byte|word|dword|qword|flt|dbl)_[0-9A-F]+\b',code)))
result=[]
def string_at(ea):
    try:
        if idaapi.is_code(idaapi.get_flags(ea)):return None
        v=idc.GetString(ea)
        if v is not None:
            s=v.decode('utf-8','strict')
            if all(ord(c)>=32 or c in '\n\r\t' for c in s):return s
    except:pass
    return None
for name in names:
    ea=idc.LocByName(name)
    if ea==idc.BADADDR:continue
    item_size=idaapi.get_item_size(ea)
    # Exact lengths from qmemcpy and matching DWARF member array dimensions.
    requests={'off_427040':120,'unk_4270C0':120,'off_427140':104,'off_4271C0':76,'unk_427220':120,'off_4272A0':68}
    size=requests.get(name,item_size)
    b=idc.GetManyBytes(ea,size)
    if b is None:continue
    row={'name':name,'address':ea,'size':size,'ida_item_size':item_size,'span_basis':'qmemcpy and DWARF dimensions' if name in requests else 'IDA item extent','type':idc.GetType(ea),'hex':b.encode('hex'),'string':string_at(ea)}
    if size%4==0 and size<=65536:
        vals=struct.unpack('<'+'I'*(size//4),b)
        candidates=[string_at(a) for a in vals]
        if candidates and all(s is not None for s in candidates):row['string_table']=candidates
    result.append(row)
open(os.path.join(root,'data_symbols.json'),'w').write(json.dumps(result,indent=2))
idaapi.qexit(0)
