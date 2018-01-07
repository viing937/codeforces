n = int(input())
m = [False] * 101
for i in range(100):
    for j in range(100):
        t = i*3 + j * 7
        if t <= 100:
            m[t] = True
for _ in range(n):
    x = int(input())
    if m[x]:
        print('YES')
    else:
        print('NO')
