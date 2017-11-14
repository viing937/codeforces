n, a = map(int, input().split(" "))
t = list(map(int, input().split(" ")))
result = t[a-1]
for i in range(1, n):
    if a-1-i >= 0 and t[a-1-i] and a-1+i < n and t[a-1+i]:
        result += 2;
    if a-1-i < 0 and a-1+i < n:
        result += t[a-1+i]
    if a-1-i >= 0 and a-1+i >= n:
        result += t[a-1-i]
print(result)
