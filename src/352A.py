# coding: utf-8
n = int(input())
a = [i for i in input().split()]
cnt_5 = a.count('5')
cnt_0 = a.count('0')
if cnt_5//9 > 0 and cnt_0 > 0:
    print(''.join(['5']*(cnt_5//9*9)+['0']*cnt_0))
elif cnt_0 > 0:
    print(0)
else:
    print(-1)
