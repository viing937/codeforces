# coding: utf-8
def judge(a,b):
    while a>1:
        b, a = a, b%a
    return a
def search(l,r):
    for i in range(l,r+1):
        for j in range(i+1,r+1):
            for k in range(j+1,r+1):
                if judge(i,j) and judge(j,k) and not judge(i,k):
                    print(i, j, k)
                    return
    print(-1)
    return
l, r = [int(i) for i in input().split()]
search(l,r)
