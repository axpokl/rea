import idaapi,idc,idautils,os,json
idaapi.auto_wait()
root=r'G:\Program Files\REA\target\MineSweeperTetris\decompiled'
name=os.path.splitext(os.path.basename(idc.GetInputFilePath()))[0]
fixed=[]
for ea in idautils.Functions():
 n=idc.GetFunctionName(ea)
 if not n.startswith('__ZN'): continue
 t=idaapi.tinfo_t(); f=idaapi.func_type_data_t()
 if idaapi.get_tinfo(t,ea) and t.get_func_details(f) and len(f)>0 and f[0].name=='this':
  f.cc=idaapi.CM_CC_THISCALL
  nt=idaapi.tinfo_t()
  if nt.create_func(f) and idaapi.apply_tinfo(ea,nt,idaapi.TINFO_DEFINITE): fixed.append(hex(ea))
idaapi.auto_wait()
import ida_hexrays
idaapi.load_plugin(r'G:\Program Files\ida64plus\plugins\hexrays.dll')
if ida_hexrays.init_hexrays_plugin():
 out=open(os.path.join(root,name+'.corrected.cpp'),'w')
 out.write('// Analysis repair: instance argument assigned to ECX (MinGW i386 thiscall).\n')
 failed=[];ok=0
 for ea in idautils.Functions():
  try:
   ida_hexrays.mark_cfunc_dirty(ea); c=ida_hexrays.decompile(ea)
   if c: out.write('\n// Address: 0x%08X; symbol: %s\n%s\n' % (ea,idc.GetFunctionName(ea),str(c)));ok+=1
  except Exception as e: failed.append({'address':hex(ea),'error':str(e)})
 out.close()
 open(os.path.join(root,name+'.corrected.status.json'),'w').write(json.dumps({'fixed_thiscall':fixed,'decompiled':ok,'failed':failed},indent=2))
idaapi.qexit(0)
