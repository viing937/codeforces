# coding: utf-8
n, m, k = [int(i) for i in input().split()]
cnt = 0
for i in input().split():
    if i == '1':
        if m > 0:
            m -= 1
        else:
            cnt += 1
    else:
        if k > 0:
            k -= 1
        elif m > 0:
            m -= 1
        else:
            cnt += 1
print(cnt)
