n = int(input())
left = []
right = []
for i in range(n):
    x, a = [int(i) for i in input().split()]
    if x < 0:
        left.append([x, a])
    else:
        right.append([x, a])
left.sort()
right.sort()
ans = 0
length = min(len(left), len(right))
for i in left[::-1]:
    if length <= 0:
        break
    ans += i[1]
    length -= 1
length = min(len(left), len(right))
for i in right:
    if length <= 0:
        break
    ans += i[1]
    length -= 1
if len(left) > len(right):
    ans += left[::-1][len(right)][1]
elif len(right) > len(left):
    ans += right[len(left)][1]
print(ans)
