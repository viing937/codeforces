n, m = map(int, input().split(" "))
row, col = [0]*n, [0]*n
numrow, numcol = n, n
result = [0] * m
for i in range(m):
    x, y = map(lambda t: int(t)-1, input().split(" "))
    if row[x] == 0:
        row[x] = 1
        numrow -= 1
    if col[y] == 0:
        col[y] = 1
        numcol -= 1
    result[i] = numrow * numcol
print(" ".join(map(str, result)))
