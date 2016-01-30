n = int(input())
points = [list(map(int, input().split(' ')))+[i+1] for i in range(n)]
points.sort()
i, j, k = 0, 1, 2
while True:
    if points[i][0] == points[j][0] and points[j][0] == points[k][0]:
        k += 1
    elif points[i][0] != points[j][0] and points[i][0] != points[k][0] and\
         (points[j][1]-points[i][1])/(points[j][0]-points[i][0]) == (points[k][1]-points[i][1])/(points[k][0]-points[i][0]):
        k += 1
    else:
        break
print(points[i][2], points[j][2], points[k][2])
