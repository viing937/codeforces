# coding: utf-8
n, m = [int(i) for i in input().split()]
cnt = 1 
while n:
    n -= 1
    if cnt%m == 0:
        n += 1
    cnt += 1
    
print(cnt-1)
