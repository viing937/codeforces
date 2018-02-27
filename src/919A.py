n, m = map(int, input().split(' '))
p = min(map(lambda x: int(x[0])/int(x[1]), [input().split(' ') for i in range(n)]))
print(m*p)
