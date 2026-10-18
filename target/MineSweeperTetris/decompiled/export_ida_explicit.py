import idaapi, idc, idautils, os, json
idaapi.auto_wait()
root=r'G:\Program Files\REA\target\MineSweeperTetris\decompiled'
name=os.path.splitext(os.path.basename(idc.GetInputFilePath()))[0]
try:
 import ida_hexrays
 loaded=idaapi.load_plugin(r'G:\Program Files\ida64plus\plugins\hexrays.dll')
 ready=ida_hexrays.init_hexrays_plugin()
 status={'name':name,'loaded':bool(loaded),'ready':ready}
 if ready:
  out=open(os.path.join(root,name+'.cpp'),'w')
  out.write('// Decompiled pseudocode; not original source. Addresses refer to this EXE.\n')
  ok=0;failed=[]
  for ea in idautils.Functions():
   try:
    c=ida_hexrays.decompile(ea)
    if c:
     out.write('\n// Address: 0x%08X; symbol: %s\n%s\n' % (ea,idc.GetFunctionName(ea),str(c))); ok+=1
   except Exception as e: failed.append({'address':hex(ea),'error':str(e)})
  out.close();status['decompiled']=ok;status['failed']=failed
except Exception as e: status={'error':str(e)}
open(os.path.join(root,name+'.status.json'),'w').write(json.dumps(status,indent=2))
idaapi.qexit(0)
