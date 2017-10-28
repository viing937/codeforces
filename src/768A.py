n = int(input())
a = sorted(map(int, input().split(" ")))
result = sum([1 if i > a[0] and i < a[-1] else 0 for i in a])
print(result)
