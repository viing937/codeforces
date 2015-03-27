# coding: utf-8
import math
def isprime(num):
    for i in range(2,int(math.sqrt(num))+1):
        if num%i == 0:
            return False
    return True
n, m = [int(i) for i in input().split()]
n += 1
while not isprime(n):
    n += 1
if n == m:
    print('YES')
else:
    print('NO')
