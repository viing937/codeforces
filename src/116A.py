# coding: utf-8
n = int(input())
capacity = -1
cnt = 0
for i in range(n):
    a, b = [int(j) for j in input().split()]
    cnt = cnt-a+b
    if cnt > capacity:
        capacity = cnt
        
print(capacity)
