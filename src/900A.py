n = int(input())
l, r = 0, 0
for _ in range(n):
    x, y = map(int, input().split())
    if x < 0:
        l += 1
    else:
        r += 1
if l <= 1 or r <= 1:
    print('Yes')
else:
    print('No')
