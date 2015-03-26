# coding: utf-8
n = int(input())
li = [0]*100005 
for i in input().split():
    i = int(i)
    li[i] += i
dp_a = 0
dp_b = li[1] 
for i in range(2,100005):
    dp_a, dp_b = dp_b, max(dp_a+li[i],dp_b)
print(dp_b)
