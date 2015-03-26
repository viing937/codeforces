# coding: utf-8
for i in range(1, 6):
    row = [j for j in input().split()]
    for j in range(1, 6):
        if row[j-1]=='1':
            x = i
            y = j
            
print(abs(x-3)+abs(y-3))
