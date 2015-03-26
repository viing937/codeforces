# coding: utf-8
m, s = [int(i) for i in input().split()]
if (s == 0 and m != 1) or s > m*9:
    print(-1,-1)
    exit()
if s == 0 and m == 1:
    print(0,0)
    exit()
minans = [1]+[0]*(m-1)
maxans = [1]+[0]*(m-1)
tmp = s-1
for i in range(m-1,-1,-1):
    if tmp >= 9-minans[i]:
        tmp -= 9-minans[i]
        minans[i] = 9
    else:
        minans[i] += tmp
        break
tmp = s-1
for i in range(0,m):
    if tmp >= 9-maxans[i]:
        tmp -= 9-maxans[i]
        maxans[i] = 9
    else:
        maxans[i] += tmp
        break
print(''.join([str(i) for i in minans]),''.join([str(i) for i in maxans]))
