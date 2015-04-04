# coding: utf-8
m, n = [int(i) for i in input().split()]
b = [[int(i) for i in input().split()] for j in range(m)]
a = [[1]*n for i in range(m)]
for i in range(m):
    for j in range(n):
        if b[i][j] == 0:
            for k in range(n):
                a[i][k] = 0
            for k in range(m):
                a[k][j] = 0
for i in range(m):
    for j in range(n):
        if b[i][j] == 1:
            if not [a[i][k] for k in range(n)].count(1) and\
               not [a[k][j] for k in range(m)].count(1):
                print('NO')
                exit()
else:
    print('YES')
    for i in range(m):
        print(' '.join([str(j) for j in a[i]]))
