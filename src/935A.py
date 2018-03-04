n = int(input())
r = sum(map(lambda x: 0 if n%x else 1, range(2, n+1)))
print(r)
