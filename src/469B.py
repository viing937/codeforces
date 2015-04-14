p, q, l ,r = [int(i) for i in input().split()]
ans = 0
mark_z = set()
mark_x = set()
for i in range(p):
    tmp = [int(j) for j in input().split()]
    for i in range(tmp[0],tmp[1]+1):
        mark_z.add(i)
for i in range(q):
    tmp = [int(j) for j in input().split()]
    for i in range(tmp[0],tmp[1]+1):
        mark_x.add(i)
for i in range(l,r+1):
    for j in mark_x:
        if j+i in mark_z:
            ans += 1
            break
print(ans)
