# coding: utf-8
n = int(input())
s = [str(i) for i in range(10)]
for i in range(n+1):
    temp = s[:i]+s[i::-1]
    length = (2*n+1-len(temp))//2
    print(' '.join([' ']*length+temp))
for i in range(n-1,-1,-1):
    temp = s[:i]+s[i::-1]
    length = (2*n+1-len(temp))//2
    print(' '.join([' ']*length+temp))
