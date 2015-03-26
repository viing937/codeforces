# coding: utf-8
x = [int(i) for i in input()]
for i in range(len(x)):
    x[i] = min(x[i],9-x[i])
if x[0] == 0:
    x[0] = 9
print(''.join([str(i) for i in x]))
