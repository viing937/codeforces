# coding: utf-8
n, v = [int(i) for i in input().split()]
ans = []
for i in range(1,n+1):
    s = [int(i) for i in input().split()][1:]
    for j in s:
        if v > j:
            ans.append(str(i))
            break
print(len(ans))
print(' '.join(ans))
