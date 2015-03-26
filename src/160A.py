# coding: utf-8
n = int(input())
coins = [int(i) for i in input().split()]
coins.sort(reverse=True)
cnt = 0
taken = 0
remained = sum(coins)
for i in coins:
    if taken > remained:
        break
    taken += i
    remained -= i
    cnt += 1
print(cnt)
