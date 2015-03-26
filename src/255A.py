# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
chest = sum([a[i] for i in range(n) if i%3==0])
biceps = sum([a[i] for i in range(n) if i%3==1])
back = sum([a[i] for i in range(n) if i%3==2])
if chest>biceps and chest>back:
    print('chest')
elif biceps>back:
    print('biceps')
else:
    print('back')
