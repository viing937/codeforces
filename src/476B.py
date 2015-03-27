# coding: utf-8
def cal(n, k):
    return c(n,k)*pow(0.5,n)
def c(n, m):
    k1 = 1
    k2 = 1
    for i in range(n-m+1,n+1):
        k1 *= i
    for i in range(1,m+1):
        k2 *= i
    return k1//k2
s1 = input()
pos1 = s1.count('+')-s1.count('-')
s2 = input()
pos2 = s2.count('+')-s2.count('-')
x = s2.count('?')
dx = abs(pos1-pos2)
if x < dx or (x-dx)%2==1:
    print(0)
else:
    print(cal(x, (x-dx)//2))
