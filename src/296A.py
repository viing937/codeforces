# coding: utf-8
from collections import Counter
n = int(input())
c = Counter([int(i) for i in input().split()])
maxtime = c.most_common()[0][1]
if n >= 2*maxtime-1:
    print('YES')
else:
    print('NO')
