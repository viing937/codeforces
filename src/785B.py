n = int(input())
chess = [list(map(int, input().split(" "))) for i in range(n)]
m = int(input())
programming = [list(map(int, input().split(" "))) for i in range(m)]

result = 0

chess.sort(key = lambda x: x[1])
programming.sort(key= lambda x: x[0])
result = max(result, programming[m-1][0] - chess[0][1])

chess.sort(key = lambda x: x[0])
programming.sort(key= lambda x: x[1])
result = max(result, chess[n-1][0] - programming[0][1])

print(result)
