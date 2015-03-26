# coding: utf-8
def cal(li):
    return max([li[i+1]-li[i] for i in range(len(li)-1)])
n = int(input())
a = [int(i) for i in input().split()]
print(min([cal(a[:i]+a[i+1:]) for i in range(1,n-1)]))
