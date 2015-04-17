# coding: utf-8
from collections import Counter
n = int(input())
c = Counter(input())
if c['I'] > 1:
    print(0)
elif c['I'] == 1:
    print(1)
else:
    print(c['A'])
