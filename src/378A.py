# coding: utf-8
a, b = [int(i) for i in input().split()]
cnt = [0]*3
for i in range(1,7):
    if abs(a-i)<abs(b-i):
        cnt[0] += 1
    elif abs(a-i)==abs(b-i):
        cnt[1] += 1
    else:
        cnt[2] += 1
print(cnt[0],cnt[1],cnt[2])
