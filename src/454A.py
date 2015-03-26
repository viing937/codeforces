# coding: utf-8
n = int(input())
s = ['*']*n
for i in range(n//2):
    s[n//2+i] = 'D'
    s[n//2-i] = 'D'
    print(''.join(s))
print('D'*n)
for i in range(n//2,0,-1):
    s[n//2+i] = '*' 
    s[n//2-i] = '*' 
    print(''.join(s))
