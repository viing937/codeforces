# coding: utf-8
n = int(input())
s1 = []
for i in range(n):
    if i%2==0:
        s1.append('C')
    else:
        s1.append('.')
s2 = []
for i in range(n):
    if i%2==1:
        s2.append('C')
    else:
        s2.append('.')
print((n*n+1)//2)
for i in range(n):
    if i%2==0:
        print(''.join(s1))
    else:
        print(''.join(s2))
