n = int(input())
l, r = [0]*n, [0]*n
for i in range(n):
    l[i], r[i] = map(int, input().split(" "))
L, R = sum(l), sum(r)
index, beauty = -1, abs(L-R)
for i in range(n):
    t = abs((L-l[i]+r[i]) - (R-r[i]+l[i]))
    if t > beauty:
        index, beauty = i, t
print(index+1)
