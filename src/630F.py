from functools import reduce

def c(n, m):
    return 0 if n>m else reduce(lambda a,b: a*b, range(m-n+1, m+1))//reduce(lambda a,b: a*b, range(1,n+1))

n = int(input())
print(sum([c(i, n) for i in range(5, 8)]))
