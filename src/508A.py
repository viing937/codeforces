# coding: utf-8
n, m, k = [int(i) for i in input().split()]
mark = [[0 for i in range(m+2)] for j in range(n+2)]
for c in range(k):
    i, j = [int(i) for i in input().split()]
    mark[i][j] = 1
    if ( mark[i-1][j-1]==1 and mark[i][j-1]==1 and mark[i-1][j]==1 ) \
    or ( mark[i][j-1]==1 and mark[i+1][j]==1 and mark[i+1][j-1]==1 ) \
    or ( mark[i][j+1]==1 and mark[i-1][j]==1 and mark[i-1][j+1]==1 ) \
    or ( mark[i][j+1]==1 and mark[i+1][j]==1 and mark[i+1][j+1]==1 ):
        print(c+1)
        break
else:
    print(0)
