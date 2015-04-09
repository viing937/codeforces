# coding: utf-8
from collections import Counter
n = int(input())
x = []
y = []
for i in range(n):
    tmp = [int(i) for i in input().split()]
    x.append(tmp[0])
    y.append(tmp[1])
xx = Counter(x)
yy = Counter(y)
for i in range(n):
    print(n-1+xx[y[i]],n-1-xx[y[i]])
