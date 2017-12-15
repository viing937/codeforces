n, m, k = map(int, input().split(" "))
roads = [list(map(int, input().split(" "))) for i in range(m)]
if k == 0:
    print(-1)
    exit()
a = set(map(int, input().split(" ")))
flag, mincost = False, 0
for road in roads:
    if (road[0] in a) ^ (road[1] in a):
        if flag:
            mincost = min(mincost, road[2])
        else:
            flag = True
            mincost = road[2]
print(mincost if flag else -1)
