from collections import Counter

n = int(input())
a = dict(Counter((map(int, input().split(' ')))))

ans = 0
while len(a) > 0:
    ans += len(a)-1
    a = dict((k, v-1) for k, v in a.items() if v > 1)

print(ans)
