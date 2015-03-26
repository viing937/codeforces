# coding: utf-8
n = int(input())
d = [int(i) for i in input().split()]
s, t = [int(i) for i in input().split()]
if s > t:
    s, t = t, s
circu = sum(d)
len1 = sum(d[s-1:t-1])
len2 = circu-len1
print(min(len1,len2))
