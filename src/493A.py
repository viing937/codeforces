# coding: utf-8
home = input()
away = input()
n = int(input())
homey = set()
homer = set()
awayy = set()
awayr = set()
ans = []
for i in range(n):
    tmp = input().split()
    if tmp[1] == 'h':
        if tmp[2] in homer:
            continue
        if tmp[3] == 'r':
            ans.append(' '.join([home, tmp[2], tmp[0]]))
            homer.add(tmp[2])
        elif tmp[2] in homey:
            ans.append(' '.join([home, tmp[2], tmp[0]]))
            homer.add(tmp[2])
        else:
            homey.add(tmp[2])
    else:
        if tmp[2] in awayr:
            continue
        if tmp[3] == 'r':
            ans.append(' '.join([away, tmp[2], tmp[0]]))
            awayr.add(tmp[2])
        elif tmp[2] in awayy:
            ans.append(' '.join([away, tmp[2], tmp[0]]))
            awayr.add(tmp[2])
        else:
            awayy.add(tmp[2])
for ln in ans:
    print(ln)
