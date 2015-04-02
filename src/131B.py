# coding: utf-8
from collections import Counter
n = int(input())
t = Counter([int(i) for i in input().split()])
tmp = t.pop(0,0)
ans = tmp*(tmp-1)//2
while t:
    tmp = t.popitem()
    ans += t.pop(-tmp[0],0)*tmp[1]
print(ans)
