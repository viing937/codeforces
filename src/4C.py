# coding: utf-8
n = int(input())
d = {}
for i in range(n):
    temp = input()
    if temp in d.keys():
        print(temp+str(d[temp]))
        d[temp] += 1
    else:
        print('OK')
        d[temp] = 1
