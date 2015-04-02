# coding: utf-8
n, r, avg = [int(i) for i in input().split()]
li = []
for i in range(n):
    tmp = [int(i) for i in input().split()]
    li.append([tmp[1],tmp[0]])
li.sort(reverse=True)
dis = avg*n-sum([i[1] for i in li])
ans = 0
while dis > 0:
    exam = li.pop()
    if dis <= r-exam[1]:
        ans += exam[0]*dis
        dis = 0
    else:
        ans += exam[0]*(r-exam[1])
        dis -= r-exam[1]
print(ans)
