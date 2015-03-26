# coding: utf-8
n = int(input())
for i in range(n):
    for j in range(n//2):
        print(i*(n//2)+j+1,1+n*n-i*(n//2)-j-1,end=' ')
    print('')
