# coding: utf-8
val_w = {'Q':9, 'R':5, 'B':3, 'N':3, 'P':1, 'K':0}
val_b = {'q':9, 'r':5, 'b':3, 'n':3, 'p':1, 'k':0}
sum_w = 0
sum_b = 0
for i in range(8):
    s = [j for j in input() if j!='.']
    for ch in s:
        if ch in val_w.keys():
            sum_w += val_w[ch]
        else:
            sum_b += val_b[ch]
if sum_w>sum_b:
    print('White')
elif sum_w==sum_b:
    print('Draw')
else:
    print('Black')
