from functools import reduce

def c(n, m):
    return 0 if n>m or n<0 else reduce(lambda a,b: a*b, range(m-n+1, m+1), 1)//reduce(lambda a,b: a*b, range(1,n+1), 1)

n = int(input())
print(pow(c(5, n), 2)*120)
