t = int(input())
for _ in range(t):
    b, p, f = map(int, input().split())
    h, c = map(int, input().split())
    if h < c:
        p, f = f, p
        h, c = c, h
    c1 = min(b // 2, p)
    c2 = min((b - 2 * c1) // 2, f)
    rls = c1 * h + c2 * c
    print(rls)
