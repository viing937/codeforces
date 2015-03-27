# coding: utf-8
s = input()
k = int(input())
w = [int(i) for i in input().split()]
li = []
for ch in s:
    li.append(w[ord(ch)-ord('a')])
li.extend([max(w)]*k)
ans = 0
for i in range(0,len(li)):
    ans += (i+1)*li[i]
print(ans)
