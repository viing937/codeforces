# coding: utf-8
n = int(input())
tmp = [int(i) for i in input().split()]
left = tmp[0]
right = tmp[0]
up = tmp[1]
down = tmp[1]
for i in range(1,n):
    tmp = [int(i) for i in input().split()]
    if left > tmp[0]:
        left = tmp[0]
    if right < tmp[0]:
        right = tmp[0]
    if up < tmp[1]:
        up = tmp[1]
    if down > tmp[1]:
        down = tmp[1]
print(pow(max(right-left,up-down),2))
