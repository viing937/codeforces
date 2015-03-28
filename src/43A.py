# coding: utf-8
n = int(input())
score = [] 
for i in range(n):
    score.append(input())
s = set(score)
if len(s) == 1:
    print(score[0])
else:
    n1 = s.pop()
    n2 = s.pop()
    if score.count(n1) > score.count(n2):
        print(n1)
    else:
        print(n2)
