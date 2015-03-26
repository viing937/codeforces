# coding: utf-8
n, m = [int(i) for i in input().split()]
d = {}
for i in range(m):
    tmp = input().split()
    d[tmp[0]] = tmp[1]
s = input().split()
for i in range(n):
    if len(s[i])>len(d[s[i]]):
        s[i] = d[s[i]]
print(' '.join(s))
