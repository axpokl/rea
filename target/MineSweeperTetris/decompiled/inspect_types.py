import idaapi,idc,idautils,os
idaapi.auto_wait()
out=open(r'G:\Program Files\REA\target\MineSweeperTetris\decompiled\member_types_before.txt','w')
for ea in idautils.Functions():
 n=idc.GetFunctionName(ea)
 if n.startswith('__ZN'):
  out.write('%X %s %s\n' % (ea,n,idc.GetType(ea)))
out.close();idaapi.qexit(0)
