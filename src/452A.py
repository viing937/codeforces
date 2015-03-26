# coding: utf-8
pokemon = ['vaporeon', 'jolteon', 'flareon', 'espeon', 'umbreon', 'leafeon', 'glaceon', 'sylveon']
n = int(input())
a = input()
for p in pokemon:
    if len(p) == n:
        for i in range(n):
            if a[i] != '.' and a[i] != p[i]:
                break
        else:
            print(p)
            exit()
