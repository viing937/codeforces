from functools import reduce

def c(n, m):
    return 0 if n>m or n<0 else reduce(lambda a,b: a*b, range(m-n+1, m+1), 1)//reduce(lambda a,b: a*b, range(1,n+1), 1)

n = int(input())
print(sum([c(i, n)*c(i-1, 2) for i in range(1, 4)])*sum([c(i, n)*c(i-1, 4) for i in range(1, 6)]))
