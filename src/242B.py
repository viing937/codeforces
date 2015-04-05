# coding: utf-8
n = int(input())
segments = [[int(i) for i in input().split()] for j in range(n)]
left = segments[0][0]
right = segments[0][1]
for seg in segments:
    if seg[0]<left:
        left = seg[0]
    if seg[1]>right:
        right = seg[1]
for i in range(n):
    if segments[i][0]<=left and segments[i][1]>=right:
        print(i+1)
        break
else:
    print(-1)
