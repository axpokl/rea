import idaapi, idc, idautils, os, json
idaapi.auto_wait()
root=r'G:\Program Files\REA\target\MineSweeperTetris\restored'
import ida_hexrays
idaapi.load_plugin(r'G:\Program Files\ida64plus\plugins\hexrays.dll')
if not ida_hexrays.init_hexrays_plugin():
    raise RuntimeError('Hex-Rays unavailable')

# Apply after plugin initialization; do not run auto_wait afterwards because
# the older DWARF importer can replace the corrected calling convention.
changes=[]
for ea in idautils.Functions():
    name=idc.GetFunctionName(ea)
    if not name.startswith('__ZN'): continue
    t=idaapi.tinfo_t(); f=idaapi.func_type_data_t()
    if idaapi.get_tinfo(t,ea) and t.get_func_details(f) and len(f)>0 and f[0].name=='this':
        before=idc.GetType(ea)
        f.cc=idaapi.CM_CC_THISCALL
        nt=idaapi.tinfo_t()
        if nt.create_func(f) and idaapi.apply_tinfo(ea,nt,idaapi.TINFO_DEFINITE):
            changes.append({'address':ea,'name':name,'before':before,'after':idc.GetType(ea)})
functions=[]; failed=[]
out=open(os.path.join(root,'improved_raw.cpp'),'w')
for ea in idautils.Functions():
    row={'address':ea,'symbol':idc.GetFunctionName(ea),'type':idc.GetType(ea)}
    try:
        ida_hexrays.mark_cfunc_dirty(ea)
        c=ida_hexrays.decompile(ea)
        if c:
            row['code']=str(c)
            out.write('\n// Address: 0x%08X; symbol: %s\n%s\n'%(ea,row['symbol'],row['code']))
        else: row['error']='no function body'
    except Exception as e:
        row['error']=str(e)
    row['assembly']=[{'address':a,'text':idc.GetDisasm(a)} for a in idautils.FuncItems(ea)]
    functions.append(row)
    if 'error' in row: failed.append({'address':ea,'name':row['symbol'],'error':row['error']})
out.close()
open(os.path.join(root,'ida_analysis.json'),'w').write(json.dumps({'calling_convention_changes':changes,'functions':functions,'failed':failed},indent=2))
idaapi.qexit(0)
