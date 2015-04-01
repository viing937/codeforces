# coding: utf-8
n, k = [int(i) for i in input().split()]
teams = []
for i in range(n):
    tmp = [int(i) for i in input().split()]
    teams.append([tmp[0],50-tmp[1]])
teams.sort(reverse=True)
print(teams.count(teams[k-1]))
