# coding: utf-8
def check(m,n):
    for i in range(n):
        for j in range(n):
            cnt = 0
            if i+1>=0 and i+1<n and m[i+1][j]=='o':
                cnt += 1
            if i-1>=0 and i-1<n and m[i-1][j]=='o':
                cnt += 1
            if j+1>=0 and j+1<n and m[i][j+1]=='o':
                cnt += 1
            if j-1>=0 and j-1<n and m[i][j-1]=='o':
                cnt += 1
            if cnt%2 == 1:
                return False
    return True
n = int(input())
m = []
for i in range(n):
    m.append([ch for ch in input()])
if check(m,n):
    print('YES')
else:
    print('NO')
