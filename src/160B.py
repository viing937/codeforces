# coding: utf-8
n = int(input())
s = [int(i) for i in input()]
left = sorted(s[:n])
right = sorted(s[n:])
if left[0]>right[0]:
    for i in range(1,n):
        if left[i]<=right[i]:
            print('NO')
            break
    else:
        print('YES')
elif left[0]<right[0]:
    for i in range(1,n):
        if left[i]>=right[i]:
            print('NO')
            break
    else:
        print('YES')
else:
    print('NO')
