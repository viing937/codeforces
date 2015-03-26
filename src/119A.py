# coding: utf-8
a, b, n = [int(i) for i in input().split()]
def gcd(a,b):
    if a < b:
        a, b = b, a
    while b!=0:
        temp = a%b
        a = b
        b = temp
    return a
flag = True
while n:
    if flag:
        n -= gcd(a,n)
    else:
        n -= gcd(b,n)
    flag = not flag
if flag:
    print('1') 
else:
    print('0')   
