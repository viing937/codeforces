n = int(input())

dire = 0
p = list(map(int, input().split(' ')))

ans = 0
for i in range(n):
    pp = list(map(int, input().split(' ')))
    if p[1] < pp[1]:
        ddire = 0
    elif p[0] > pp[0]:
        ddire = 1
    elif p[1] > pp[1]:
        ddire = 2
    elif p[0] < pp[0]:
        ddire = 3
    if (dire+1)%4 == ddire:
        ans += 1
    p, dire = pp, ddire

print(ans)
