# coding: utf-8
from collections import Counter
n, m = [int(i) for i in input().split()]
a = Counter([int(i) for i in input().split()])
b = Counter([int(i) for i in input().split()])
aa = sorted(list((a-b).elements()))
bb = sorted(list((b-a).elements()))
cnt = sum(a.values())-len(aa)
i = 0
j = 0
while i < len(aa):
    while j < len(bb) and bb[j]<aa[i]:
        j += 1
    if j < len(bb) and bb[j]>aa[i]:
        cnt += 1
        j += 1
    i += 1
print(n-cnt)
