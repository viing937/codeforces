n = int(input())
left = []
right = []
for i in range(n):
    x, a = [int(i) for i in input().split()]
    if x < 0:
        left.append([x, a])
    else:
        right.append([x, a])
left.sort(reverse=True)
right.sort()
ans = 0
length = min(len(left), len(right))
for i in range(length):
    ans += left[i][1]
    ans += right[i][1]
if len(left) > len(right):
    ans += left[length][1]
elif len(right) > len(left):
    ans += right[length][1]
print(ans)
