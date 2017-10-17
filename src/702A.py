n = int(input())
a = list(map(int, input().split(" ")))
result, cnt = 1, 1
for i in range(1, n):
    if a[i] > a[i-1]:
        cnt += 1
    else:
        cnt = 1
    result = max(result, cnt)
print(result)
