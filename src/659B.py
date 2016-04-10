n, m = map(int, input().split(' '))
c = {}

for i in range(n):
    line = input().split()
    line[1], line[2] = int(line[1]), int(line[2])
    if line[1] not in c:
        c[line[1]] = []
    c[line[1]].append((line[2], line[0]))

for i in range(1, m+1):
    c[i].sort(reverse = True)
    if len(c[i]) > 2 and c[i][1][0] == c[i][2][0]:
        print('?')
    else:
        print(c[i][0][1], c[i][1][1])
