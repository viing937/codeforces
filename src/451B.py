# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
start = -1 
end = -1
for i in range(n-1):
    if start==-1 and a[i]>a[i+1]:
        start = i
        end = i+1
    elif a[i]>a[i+1]:
        end = i+1
a = a[:start] + a[start:end+1][::-1] + a[end+1:]
if start==-1:
    print('yes')
    print(1,1)
elif a==sorted(a):
    print('yes')
    print(start+1,end+1)
else:
    print('no')
