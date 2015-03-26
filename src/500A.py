# coding: utf-8
n, t = [int(i) for i in input().split()]
tt = [int(i) for i in input().split()]
pos = 1
while pos < t:
    pos += tt[pos-1]
if pos == t:
    print('YES')
else:
    print('NO')
