# coding: utf-8
import itertools
g = [[int(i) for i in input().split()] for i in range(5)]
permutations = list(itertools.permutations([0,1,2,3,4],5))
ans = -1
for per in permutations:
    tmp = (g[per[0]][per[1]]+g[per[1]][per[0]])*1\
        + (g[per[1]][per[2]]+g[per[2]][per[1]])*1\
        + (g[per[2]][per[3]]+g[per[3]][per[2]])*2\
        + (g[per[3]][per[4]]+g[per[4]][per[3]])*2
    if tmp > ans:
        ans = tmp
print(ans)
