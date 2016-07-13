n = int(input())
a = list(map(int, input().split()))

x, y = a.index(1), a.index(n)
if x > y:
    x, y = y, x

if x == 0 or y == n-1:
    print(n-1)
else:
    print(max(n-1-x, y))
