n, m = [int(i) for i in input().split()]
cnt = list([0]*(n+1))
for i in range(m):
    votes = [int(num) for num in input().split()]
    maxnum = max(votes)
    cnt[votes.index(maxnum)] += 1
maxnum = max(cnt)
print(cnt.index(maxnum)+1)
