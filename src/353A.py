# coding: utf-8
n = int(input())
upper = 0
lower = 0
flag = False
for i in range(n):
    tmp = [int(i) for i in input().split()]
    upper += tmp[0]%2
    lower += tmp[1]%2
    if tmp[0]%2 != tmp[1]%2:
        flag = True
if upper%2==0 and lower%2==0:
    print(0)
elif upper%2+lower%2 == 1 or not flag:
    print(-1)
else:
    print(1)
