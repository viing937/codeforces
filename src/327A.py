# coding: utf-8
n = int(input())
s = input().split()
li = []
for ch in s:
    if ch == '1':
        li.append(-1)
    else:
        li.append(1)
maxsum = li[0] 
thissum = 0 
for i in li:
    thissum += i
    if thissum > maxsum:
        maxsum = thissum
    elif thissum < 0:
        thissum = 0
print(s.count('1')+maxsum)
