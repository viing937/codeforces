from collections import Counter
n, k = map(int, input().split(' '))
m = Counter(input())
result = True
for key in m:
    if m[key] > k:
        result = False
if result:
    print("YES")
else:
    print("NO")
