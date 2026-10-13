import idaapi, idc
idaapi.auto_wait()
try:
 import ida_hexrays
 if not ida_hexrays.init_hexrays_plugin(): raise Exception('no hexrays')
 out=open(r'G:\\Program Files\\REA\\target\\MineSweeperTetris\\analysis\\debug2_pseudocode.cpp','w')
 for ea in Functions():
  try:
   c=ida_hexrays.decompile(ea)
   if c: out.write('// 0x%08X %s\n%s\n\n' % (ea,GetFunctionName(ea),str(c)))
  except Exception as e: out.write('// failed 0x%08X %s\n' % (ea,str(e)))
 out.close()
except Exception as e:
 open(r'G:\\Program Files\\REA\\target\\MineSweeperTetris\\analysis\\hexrays_error.txt','w').write(str(e))
idaapi.qexit(0)
