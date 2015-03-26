# coding: utf-8
n, t = [int(i) for i in input().split()]
queue = list(input())
for i in range(t):
    queue_new = list(queue)
    for j in range(n-1):
        if queue[j]=='B' and queue[j+1]=='G':
            queue_new[j], queue_new[j+1] = queue_new[j+1], queue_new[j]
    queue = list(queue_new)
print(''.join(queue))
