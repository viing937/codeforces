# coding: utf-8
x, y, z = [int(i) for i in input().split()]
for a in range(1,x+1):
    b = x//a
    c = z//a
    if a*b==x and b*c==y and a*c==z:
        print((a+b+c)*4)
