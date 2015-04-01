# coding: utf-8
k = int(input())
l = [['#']*11,['#']*11,['#'],['#']*11]
if k > 4:
    for i in range(4):
        l[i][0] = 'O'
    k -= 4
else:
    for i in range(k):
        l[i][0] = 'O'
    k = 0
for i in range(1,(k+2)//3+1):
    if k >= 3:
        k -= 3
        l[0][i] = 'O'
        l[1][i] = 'O'
        l[3][i] = 'O'
    elif k == 2:
        k = 0
        l[0][i] = 'O'
        l[1][i] = 'O'
    elif k == 1:
        k = 0
        l[0][i] = 'O'
print('+------------------------+')
print('|','.'.join(l[0]),'.|D|)',sep='')
print('|','.'.join(l[1]),'.|.|',sep='')
print('|',l[2][0],'.......................|',sep='')
print('|','.'.join(l[3]),'.|.|)',sep='')
print('+------------------------+')
