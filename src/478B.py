# coding: utf-8
n, m = [int(i) for i in input().split()]
if n%m==0:
    kmin = (n//m)*(n//m-1)//2*m
    kmax = (n-m+1)*(n-m)//2
else:
    t = n//m
    kmin = t*(t+1)//2*(n%m)+t*(t-1)//2*(m-n%m)
    kmax = (n-m+1)*(n-m)//2
print(kmin,kmax)    
