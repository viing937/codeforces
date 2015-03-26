# coding: utf-8
num = input()

cnt = num.count('4')+num.count('7')
if cnt == 4 or cnt == 7:
    print('YES')
else:
    print('NO')
