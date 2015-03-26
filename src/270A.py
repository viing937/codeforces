# coding: utf-8
n = int(input())
li = []
angle = 180
num = 3
while angle/num<=179:
    if angle%num == 0:
        li.append(angle//num)
    angle += 180
    num += 1
for i in range(n):
    t = int(input())
    if t in li:
        print('YES')
    else:
        print('NO')
