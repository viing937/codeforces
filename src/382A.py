# coding: utf-8
left, right = [list(i) for i in input().split('|')]
for i in input():
    if len(left)>len(right):
        right.append(i)
    else:
        left.append(i)
if len(left) == len(right):
    print(''.join(left)+'|'+''.join(right))
else:
    print('Impossible')
