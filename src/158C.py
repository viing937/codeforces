# coding: utf-8
n = int(input())
path = []
for i in range(n):
    temp = input()
    if len(temp.split())==1:
        if path:
            print('/'+'/'.join(path)+'/')
        else:
            print('/')
    else:
        temp = temp.split()[1]
        if temp[0] == '/':
            path = []
        for j in [ch for ch in temp.split('/') if ch!='']:
            if j != '..':
                path.append(j)
            else:
                path.pop()
