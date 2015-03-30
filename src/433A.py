# coding: utf-8
n = int(input())
w = [int(i) for i in input().split()]
num_100 = w.count(100)
num_200 = w.count(200)
if num_100%2==0 and num_200%2==0:
    print('YES')
elif num_100>=2 and num_100%2==0 and num_200%2==1:
    print('YES')
else:
    print('NO')
