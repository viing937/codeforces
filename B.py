from collections import Counter
n = int(input())
a = [int(i) for i in input().split()]
c = Counter(a)
cnt = c.most_common()[0][1]
l = 1
r = n
for i in c.most_common():
    if i[1] == cnt:
        ll = a.index(i[0])+1
        rr = n-a[::-1].index(i[0])
        if rr-ll < r-l:
            r = rr
            l = ll
    else:
        break
print(l, r)
