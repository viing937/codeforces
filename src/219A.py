# coding: utf-8
k = int(input())
s = input()
copy = []
for ch in set(s):
    cnt = s.count(ch)
    if cnt%k==0:
        copy.append(ch*(cnt//k))
    else:
        copy = []
        break
if copy:
    print(''.join(copy*k))
else:
    print(-1)
