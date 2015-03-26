# coding: utf-8
a, b, s = [int(i) for i in input().split()]
cnt = abs(a)+abs(b)
if s>=cnt and (s-cnt)%2==0:
    print('Yes')
else:
    print('No')
