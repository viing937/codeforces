n, m = [int(i) for i in input().split()]
if n-m > m-1:
    print(min(m+1, n))
else:
    print(max(m-1, 1))
