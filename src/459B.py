# coding: utf-8
n = int(input())
li = [int(i) for i in input().split()]
max_num = max(li)
min_num = min(li)
if max_num != min_num:
    print(max_num-min_num, li.count(max_num)*li.count(min_num))
else:
    print(0, li.count(max_num)*(li.count(max_num)-1)//2)
