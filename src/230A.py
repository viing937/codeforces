# coding: utf-8
s, n = [int(i) for i in input().split()]
li = {}
for i in range(n):
    x, y = [int(i) for i in input().split()]
    if x in li.keys():
        li[x] += y
    else:
        li[x] = y
for i in sorted(li.keys()):
    if s > i:
        s += li[i]
    else:
        print('NO')
        break
else:
    print('YES')
