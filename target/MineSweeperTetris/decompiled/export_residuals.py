import idaapi,idc,idautils,os,json
idaapi.auto_wait()
root=r'G:\Program Files\REA\target\MineSweeperTetris\decompiled'
name=os.path.splitext(os.path.basename(idc.GetInputFilePath()))[0]
s=json.load(open(os.path.join(root,name+'.status.json')))
out=open(os.path.join(root,name+'.failed_functions.asm'),'w')
for row in s['failed']:
 ea=int(row['address'].rstrip('L'),16)
 out.write('\n; Failed pseudocode: 0x%08X %s\n' % (ea,idc.GetFunctionName(ea)))
 for item in idautils.FuncItems(ea): out.write('%08X  %s\n' % (item,idc.GetDisasm(item)))
out.close()
out=open(os.path.join(root,name+'.types.h'),'w')
for n in range(1,idc.GetMaxLocalType()):
 try:
  t=idc.GetLocalType(n,idc.PRTYPE_MULTI)
  if t: out.write(t+';\n\n')
 except: pass
out.close();idaapi.qexit(0)
