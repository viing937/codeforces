n = int(input())
a = sorted(list(map(int, input().split(' '))))

if n == 1:
    print(-1)
    exit()

if n == 2 and (a[1]-a[0])%2 == 0 and a[0] != a[1]:
    print(3)
    print(2*a[0]-a[1], (a[0]+a[1])//2, 2*a[1]-a[0])
    exit()

m = sorted([a[i]-a[i-1] for i in range(1, n)])

if len(set(m)) == 1:
    if m[0] != 0:
        print(2)
        print(a[0]-m[0], a[-1]+m[0])
    else:
        print(1)
        print(a[0])
    exit()

if len(set(m)) > 2 or m[-1] != 2*m[-2]:
    print(0)
else:
    print(1)
    for i in range(1, n):
        if a[i]-a[i-1] != m[0]:
            print(a[i-1]+m[0])
