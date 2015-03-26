# coding: utf-8
k = int(input())
a = [int(i) for i in input().split()]
a.sort(reverse=True)
cnt = 0
heigth = 0
if k == 0:
    print(0)
else:
    for i in a:
        heigth += i
        cnt += 1
        if heigth >= k:
            print(cnt)
            break
    else:
        print('-1')
