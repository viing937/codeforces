# coding: utf-8
light = [[0,0,0,0,0] for i in range(5)]
for i in range(1,4):
    s = [int(i) for i in input().split()]
    for j in range(1,4):
        light[i][j] += s[j-1]
        light[i-1][j] += s[j-1]
        light[i+1][j] += s[j-1]
        light[i][j-1] += s[j-1]
        light[i][j+1] += s[j-1]
for i in range(1,4):
    for j in range(1,4):
        if light[i][j]%2==1:
            print(0,end='')
        else:
            print(1,end='')
    print()
