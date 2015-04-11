# coding: utf-8
a, b, c = [int(i) for i in input().split()]
for x in range(a+1):
    y = b-x
    z = a-x
    if y>=0 and z>=0 and y+z==c:
        print(x,y,z)
        break
else:
    print('Impossible')
