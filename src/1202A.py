T = int(input())
for _ in range(T):
    x = input()[::-1]
    y = input()[::-1]
    idx = y.index('1')
    rls = 0
    while idx < len(x) and x[idx] != '1':
        rls += 1
        idx += 1
    print(rls)
