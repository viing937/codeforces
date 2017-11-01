n = int(input())
a = list(map(int, input().split(' ')))
code, sport = [0]*n, [0]*n
for i in range(n):
    code[i] = max(code[i], a[i]%2)
    sport[i] = max(sport[i], a[i]//2)
    for j in range(i+1, n):
        if a[j]%2:
            code[j] = max(code[j], sport[i] + 1)
        if a[j]//2:
            sport[j] = max(sport[j], code[i] + 1)
    for j in range(i+2, n):
        if a[j]%2:
            code[j] = max(code[j], code[i] + 1)
        if a[j]//2:
            sport[j] = max(sport[j], sport[i] + 1)
result = n - max(max(code), max(sport))
print(result)
