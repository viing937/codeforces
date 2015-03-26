# coding: utf-8
c = [int(i) for i in input().split()]
cc = sum(c)
if cc == 0 or cc%5 != 0:
    print('-1')
else:
    print(cc//5)
