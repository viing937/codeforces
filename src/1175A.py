def func(n, k):
    if n == 0:
        return 0
    elif n%k:
        return n%k + func(n//k*k, k)
    else:
        return 1 + func(n//k, k)

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    rls = func(n, k)
    print(rls)
