#!/usr/bin/python3

import re
import sys
temp = 0.0
t2=0.0
f = open(sys.argv[1], 'r')
for line in f:
	match = re.search(r'Time: (\d+.\d+)',line)
	if match:
		temp+=float(match.group(1))
print("%f" %(temp/10))
f.close()
