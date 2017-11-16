n, m = map(int, input().split(" "))
result = 0
for i in range(5):
    a = n//5 + (1 if i != 0 and i <= n%5 else 0)
    b = m//5 + (1 if (5-i) <= m%5 else 0)
    result += a*b
print(result)
