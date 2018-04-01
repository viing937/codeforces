n, k = map(int, input().split())
t = 2**n-1
while k != (t+1)//2:
    n -= 1
    t //= 2
    if k > t:
        k -= t+1
print(n)
