# coding: utf-8
n, m = [int(i) for i in input().split()]
if not m:
    print('YES')
    exit()
d = [int(i) for i in input().split()]
if n in d or 1 in d:
    print('NO')
    exit()
d.sort()
i = 0
for i in range(m-2):
    if d[i+2]-d[i+1]==1 and d[i+1]-d[i]==1:
        print('NO')
        break
else:
    print('YES')
