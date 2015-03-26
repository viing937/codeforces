# coding: utf-8
n = int(input())
sta = [i for i in ''.join(input().split()).split('0') if i != '']
ans = 0
for i in sta:
    ans += 2+len(i)-1
if ans != 0:
    print(ans-1)
else:
    print(0)
