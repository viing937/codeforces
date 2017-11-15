n, b, d = map(int, input().split(" "))
result, waste = 0, 0
for a in map(int, input().split(" ")):
    if a > b:
        continue
    waste += a
    if waste > d:
        waste = 0
        result += 1
print(result)
