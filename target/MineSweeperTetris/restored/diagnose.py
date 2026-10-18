import idaapi,idc,idautils,json
idaapi.auto_wait()
import ida_hexrays
idaapi.load_plugin(r'G:\Program Files\ida64plus\plugins\hexrays.dll')
ida_hexrays.init_hexrays_plugin()
o=open(r'G:\Program Files\REA\target\MineSweeperTetris\restored\diagnostic.txt','w')
for ea in [0x401714,0x401800]:
 o.write('BEFORE '+str(idc.GetType(ea))+'\n')
 for a in list(idautils.FuncItems(ea))[:22]:o.write('%X %s\n'%(a,idc.GetDisasm(a)))
 t=idaapi.tinfo_t();f=idaapi.func_type_data_t();idaapi.get_tinfo(t,ea);t.get_func_details(f);f.cc=idaapi.CM_CC_THISCALL
 nt=idaapi.tinfo_t();nt.create_func(f);o.write('APPLY '+str(idaapi.apply_tinfo(ea,nt,idaapi.TINFO_DEFINITE))+'\n')
 o.write('AFTER '+str(idc.GetType(ea))+'\n');ida_hexrays.mark_cfunc_dirty(ea)
 try:o.write(str(ida_hexrays.decompile(ea))+'\n')
 except Exception as e:o.write(str(e)+'\n')
o.close();idaapi.qexit(0)
