n = int(input())
a = [int(i) for i in input().split(' ')]
b = [int(i) for i in input().split(' ')]

count = [0]*6

for i in range(1, 6):
    count[i] = a.count(i) - b.count(i)

ans = 0

for i in range(1, 6):
    for j in range(i+1, 6):
        if count[i] * count[j] < 0:
            t = min(abs(count[i]), abs(count[j]))//2
            ans += t
            count[i] += t*2 if count[i] < 0 else -t*2;
            count[j] += t*2 if count[j] < 0 else -t*2;

if count.count(0) == 6:
    print(ans)
else:
    print(-1)
