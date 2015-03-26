# coding: utf-8
import re
p = re.compile('.*h.*e.*l.*l.*o.*')
s = input()
if p.match(s):
    print('YES')
else:
    print('NO')
