# coding: utf-8
n = int(input())
name = []
for i in range(n):
    name.append(sorted(input().split()))
p = [int(i) for i in input().split()]
pre = name[p[0]-1][0]
for index in p[1:]:
    if name[index-1][0]>pre:
        pre = name[index-1][0]
    elif name[index-1][1]>pre:
        pre = name[index-1][1]
    else:
        print('NO')
        break
else:
    print('YES') 
