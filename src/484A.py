import math
def f(l,r):
    if l == r:
        return l
    else:
        b = int(math.log(r,2))
        if p[b] <= l:
            return f(l-p[b],r-p[b])+p[b]
        elif p[b+1]-1 <= r:
            return p[b+1]-1
        else:
            return p[b]-1
p = [1]
for i in range(64):
    p.append(p[-1]*2)
n = int(input())
for i in range(n):
    l, r = [int(i) for i in input().split()]
    print(f(l,r))
