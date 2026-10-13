import idaapi, idc
idaapi.auto_wait()
out = open(r'G:\\Program Files\\REA\\target\\MineSweeperTetris\\analysis\\debug1_functions.txt','w')
for ea in Functions():
    out.write('0x%08X %s\n' % (ea, GetFunctionName(ea)))
out.close(); idaapi.qexit(0)
