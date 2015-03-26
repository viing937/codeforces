# coding: utf-8
a, b = [int(i) for i in input().split()]
aa = 0
cnt = 0
while a:
    cnt += a
    aa += a
    a = aa//b
    aa = aa%b
    
print(cnt)
