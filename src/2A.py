# coding: utf-8
n = int(input())
score = {}
li = []
for i in range(n):
    tmp = input().split()
    li.append(tmp)
    if tmp[0] in score.keys():
        score[tmp[0]] += int(tmp[1])
    else:
        score[tmp[0]] = int(tmp[1])
maxscore = max(score.values())
winners = []
while score:
    tmp = score.popitem()
    if maxscore == tmp[1]:
        winners.append(tmp[0])
for winner in winners:
    score[winner] = 0
for ln in li:
    if ln[0] in winners:
        score[ln[0]] += int(ln[1])
        if score[ln[0]] >= maxscore:
            print(ln[0])
            exit()
