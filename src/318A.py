# coding: utf-8
n, k = [int(i) for i in input().split()]
num_odd = (n+2-1)//2
if k <= num_odd:
    print(k*2-1)
else:
    print((k-num_odd)*2)
