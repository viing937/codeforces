l, r, k = map(int, input().split(' '))
ans = []
t = 1
while t <= r:
    if t >= l:
        ans.append(t)
    t *= k
if len(ans) > 0:
    print(' '.join(map(str, ans)))
else:
    print(-1)
