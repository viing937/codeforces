# coding: utf-8
n = int(input())
h = []
a = []
for i in range(n):
    hh, aa = [int(i) for i in input().split()]
    h.append(hh)
    a.append(aa)
cnt = 0
for i in h:
    cnt += a.count(i)
print(cnt)
