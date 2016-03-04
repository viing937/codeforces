n, m, k = map(int, input().split(' '))

row, col = [(0,0)]*n, [(0,0)]*m
for i in range(k):
    t, r, a = map(int, input().split(' '))
    if t == 1:
        row[r-1] = (a, i+1)
    elif t == 2:
        col[r-1] = (a, i+1)

sheet = [[0]*m for i in range(n)]
for i in range(n):
    for j in range(m):
        if row[i][1] >= col[j][1]:
            sheet[i][j] = row[i][0]
        else:
            sheet[i][j] = col[j][0]
    print(' '.join(map(str, sheet[i])))
