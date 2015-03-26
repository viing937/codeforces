# coding: utf-8
def gcd(a,b):
    if a > b:
        a, b = b, a
    for i in range(a,0,-1):
        if a%i==0 and b%i==0:
            return i;
def lcm(a,b):
    return a*b//gcd(a,b)
x, y, a, b = [int(i) for i in input().split()]
common = lcm(x,y)
if a%common !=0 :
    a = a+common-a%common
print((b-a)//common+1)
