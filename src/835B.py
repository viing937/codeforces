from collections import Counter
k = int(input())
n = Counter(map(int, input()))
t = sum(map(lambda x: x[0]*x[1], n.items()))
result = 0
for i in range(0, 11):
    if t >= k:
        break
    c = min(n[i], (k-t+8-i)//(9-i))
    t += c * (9-i)
    result += c
print(result)
