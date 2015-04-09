# coding: utf-8
s = [[int(i) for i in input().split()] for j in range(3)]
x = 0
while True:
    x += 1
    sumk = x + s[0][1] + s[0][2]
    y = sumk - s[1][0] - s[1][2]
    z = sumk - s[2][0] - s[2][1]
    if x+s[1][0]+s[2][0]==sumk and\
       s[0][1]+y+s[2][1]==sumk and\
       s[0][2]+s[1][2]+z==sumk and\
       x+y+z==sumk and\
       s[0][2]+y+s[2][0]==sumk:
        s[0][0] = x
        s[1][1] = y
        s[2][2] = z
        break
for i in range(3):
    print(' '.join([str(j) for j in s[i]]))
