# coding: utf-8
n = int(input())
li = [int(i) for i in input().split()]
cnt = {25:0, 50:0, 100:0}
for i in li:
    if i == 25:
        cnt[25] += 1
    elif i == 50:
        if cnt[25] == 0:
            print('NO')
            break
        else:
            cnt[25] -= 1
            cnt[50] += 1
    else:
        if cnt[50]>0 and cnt[25]>0:
            cnt[50] -= 1
            cnt[25] -= 1
            cnt[100] += 1
        elif cnt[25]>=3:
            cnt[25] -= 3
            cnt[100] += 1
        else:
            print('NO')
            break
else:
    print('YES') 
