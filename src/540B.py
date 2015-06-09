n, k, p, x, y = [int(i) for i in input().split()]
left = 0
for a in input().split():
    a = int(a)
    x -= a
    if a < y:
        left += 1
if left > n//2:
    print(-1)
    exit()
elif k-left > n//2:
    ans = [1]*(n-k)
else:
    ans = [1]*(n//2-left)+[y]*((n+1)//2-(k-left))
if sum(ans) > x:
    print(-1)
else:
    print(" ".join([str(i) for i in ans]))
