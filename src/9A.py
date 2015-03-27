# coding: utf-8
y, w = [int(i) for i in input().split()]
prob = 7-max(y,w)
if prob==6:
    print('1/1')
elif prob==5:
    print('5/6')
elif prob==4:
    print('2/3')
elif prob==3:
    print('1/2')
elif prob==2:
    print('1/3')
elif prob==1:
    print('1/6')
