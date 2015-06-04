n, m = [int(i) for i in input().split()]
a = [input().split() for i in range(n)]
while n%2==0:
    if a[:n//2] == a[n//2:n][::-1]:
        n //= 2
    else:
        break
print(n)
