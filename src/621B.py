n = int(input())

cnt1, cnt2 = {}, {}
for i in range(n):
    x, y = map(int, input().split())
    cnt1[x+y] = cnt1.get(x+y, 0) + 1
    cnt2[x-y] = cnt2.get(x-y, 0) + 1

ans = 0
for t in cnt1.values():
    ans += t*(t-1)//2
for t in cnt2.values():
    ans += t*(t-1)//2
print(ans)
