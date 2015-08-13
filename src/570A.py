n, m = [int(i) for i in input().split()]
cnt = list([0]*(n+1))
for i in range(m):
    votes = [int(num) for num in input().split()]
    cnt[votes.index(max(votes))] += 1
print(cnt.index(max(cnt))+1)
