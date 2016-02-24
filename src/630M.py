x = int(input())%360

ans = 0
for i in range(1, 4):
    if min(abs(x-i*90), abs(360-x+i*90)) < min(abs(x-ans*90), abs(360-x+ans*90)):
        ans = i

print(ans)
