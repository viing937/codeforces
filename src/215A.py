# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
m = int(input())
b = [int(i) for i in input().split()]
maxratio = -1
ans = 0
for bb in b[::-1]:
    for aa in a:
        if bb//aa < maxratio:
            break
        elif bb%aa != 0:
            continue
        elif bb//aa > maxratio:
            maxratio = bb//aa
            ans = 1
        else:
            ans += 1
print(ans)
