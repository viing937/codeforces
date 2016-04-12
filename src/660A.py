def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)

n = int(input())
a = list(map(int, input().split(' ')))

aa = [a[0]]
for i in range(1, n):
    if gcd(aa[-1], a[i]) > 1:
        aa.append(1)
    aa.append(a[i])

print(len(aa)-n)
print(' '.join(map(str, aa)))
