# coding: utf-8
s = input()
cnt = [0,0]
for i in set(s):
    cnt[s.count(i)%2] += 1
if (cnt[1] and cnt[1]%2) or (not cnt[1]):
    print('First')
else:
    print('Second')
