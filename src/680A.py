t = sorted(list(map(int, input().split(" "))))
s = sum(t)
result = s
for i in range(4):
    if t[i] == t[i+1]:
        result = min(result, s-sum(t[i:i+2]))
for i in range(3):
    if t[i] == t[i+2]:
        result = min(result, s-sum(t[i:i+3]))
print(result)
