# coding: utf-8
n, m = [int(i) for i in input().split()]
correct = [int(i) for i in input().split()]
wrong = [int(i) for i in input().split()]
low = max(2*min(correct),max(correct))
up = min(wrong)
if low < up:
    print(low)
else:
    print(-1)
