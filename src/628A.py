import math

def cal(n):
    result = 0
    while n > 1:
        t = pow(2, int(math.log2(n)))
        result += t-1
        n = n-t+1
    return result

n, b, p = map(int, input().split(' '))
print((2*b+1)*cal(n), n*p)
