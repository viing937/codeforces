# coding: utf-8
num = [i for i in input().split('+')]
num.sort()
for i in range(len(num)):
    if i == 0:
        print(num[i],end='')
    else:
        print('+',num[i],sep='',end='')
print('')
