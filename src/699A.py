n = int(input())
d = input()
x = list(map(int, input().split()))
result = -1
for i in range(1, n):
    if d[i-1] != 'R' or d[i] != 'L':
        continue
    if result == -1:
        result = (x[i]-x[i-1])//2
    else:
        result = min(result, (x[i]-x[i-1])//2)
print(result)
