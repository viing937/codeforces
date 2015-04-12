# coding: utf-8
n = int(input())
first = []
second = []
for i in range(n):
    a = int(input())
    if a > 0:
        first.append(a)
        flag = True
    else:
        second.append(-a)
        flag = False
sum_first = sum(first)
sum_second = sum(second)
if sum_first > sum_second:
    print('first')
elif sum_first < sum_second:
    print('second')
elif first > second:
    print('first')
elif first < second:
    print('second')
elif flag:
    print('first')
else:
    print('second')
