# coding: utf-8
n, s = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
if sum(a)-max(a) <= s:
    print('YES')
else:
    print('NO')
