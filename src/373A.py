# coding: utf-8
from collections import Counter
k = int(input())
s = ''
for i in range(4):
    s += input()
s  = Counter(s)
if '.' in s.keys():
    s.pop('.')
while s:
    if s.popitem()[1]>2*k:
        print('NO')
        break
else:
    print('YES')
