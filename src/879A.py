n = int(input())
today = 1
for _ in range(n):
    s, d = map(int, input().split())
    if today > s:
        today = s + (today-s+d-1)//d*d + 1
    else:
        today = s + 1
print(today-1)
