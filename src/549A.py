n, m = [int(i) for i in input().split()]
image = [input() for i in range(n)]
ans = 0
for i in range(n-1):
    for j in range(m-1):
        if len(set([image[i][j],image[i][j+1],image[i+1][j],image[i+1][j+1]])&set(['f','a','c','e'])) == 4:
            ans += 1
print(ans)
