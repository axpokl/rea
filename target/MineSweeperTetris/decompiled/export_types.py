import idaapi,idc,idautils,os
idaapi.auto_wait()
root=r'G:\Program Files\REA\target\MineSweeperTetris\decompiled'
name=os.path.splitext(os.path.basename(idc.GetInputFilePath()))[0]
out=open(os.path.join(root,name+'.types.h'),'w')
for n in range(1,idc.GetMaxLocalType()):
 try:
  t=idc.GetLocalType(n,idc.PRTYPE_MULTI)
  if t: out.write(t+';\n\n')
 except: pass
out.close()
idaapi.qexit(0)
