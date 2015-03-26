# coding: utf-8
n, m = [int(i) for i in input().split()]
mul = 0
while True:
    mul += 1
    moves = mul*m
    if n>=moves and n<=moves*2:
        print(moves)
        break
    elif moves > n:
        print(-1)
        break
