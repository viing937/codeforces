# coding: utf-8
n, m = [int(i) for i in input().split()]
s1 = '#'*m
s2 = '.'*(m-1)
for i in range(n):
    if i%2 == 0:
        print(s1)
    elif i%4 == 1:
        print(s2,'#',sep='')
    else:
        print('#',s2, sep='')
