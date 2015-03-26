# coding: utf-8
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
n = int(input())
cnt = (sum(a)+5-1)//5 + (sum(b)+10-1)//10
if (cnt<=n):
    print('YES')
else:
    print('NO')
