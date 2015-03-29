# coding: utf-8
x, y = [int(i) for i in input().split()]
n = int(input())
if n%6==1:
    print(x%1000000007)
elif n%6==2:
    print(y%1000000007)
elif n%6==3:
    print((y-x)%1000000007)
elif n%6==4:
    print((-x)%1000000007)
elif n%6==5:
    print((-y)%1000000007)
elif n%6==0:
    print((x-y)%1000000007)
