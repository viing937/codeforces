T = int(input())
for _ in range(T):
    n = int(input())
    a = sorted(map(int, input().split()))
    if n < 3:
        print(0)
        continue
    baseLength = min(a[-2:])
    steps = len(list(filter(lambda x: x >= 1, a[:-2])))
    print(min(steps, baseLength-1))
