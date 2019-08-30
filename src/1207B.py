n, m = map(int, input().split())
A = [list(map(int, input().split())) for i in range(n)]
B = [[0] * m for i in range(n)]

offset = [(0, 0), (1, 0), (0, 1), (1, 1)]


def check(x, y):
    if x < 0 or y < 0:
        return False
    if x + 1 >= n or y + 1 >= m:
        return False
    for dx, dy in offset:
        if not A[x + dx][y + dy]:
            return False
    return True


rls = []
for i in range(n):
    for j in range(m):
        if not A[i][j] or B[i][j]:
            continue
        for dx, dy in offset:
            x, y = i - 1 + dx, j - 1 + dy
            if check(x, y):
                B[x][y] = B[x + 1][y] = B[x][y + 1] = B[x + 1][y + 1] = 1
                rls.append([x + 1, y + 1])
                break
        else:
            print(-1)
            exit()

print(len(rls))
for i, j in rls:
    print(i, j)
