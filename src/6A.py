# coding: utf-8
from itertools import combinations
l = [int(i) for i in input().split()]
comb = list(combinations([0,1,2,3],3))
for c in comb:
    if l[c[0]]+l[c[1]]>l[c[2]] and\
       l[c[1]]+l[c[2]]>l[c[0]] and\
       l[c[0]]+l[c[2]]>l[c[1]]:
        print('TRIANGLE')
        exit()
for c in comb:
    if l[c[0]]+l[c[1]]==l[c[2]] or\
       l[c[1]]+l[c[2]]==l[c[0]] or\
       l[c[0]]+l[c[2]]==l[c[1]]:
        print('SEGMENT')
        exit()
print('IMPOSSIBLE')
