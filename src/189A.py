# coding: utf-8
n, a, b, c = [int(i) for i in input().split()]
dp = [0]*4001
dp[a] = 1
dp[b] = 1
dp[c] = 1
for i in range(n+1):
    if i-a>=0 and dp[i-a]!=0:
        dp[i] = max(dp[i-a]+1,dp[i])
    if i-b>=0 and dp[i-b]!=0:
        dp[i] = max(dp[i-b]+1,dp[i])
    if i-c>=0 and dp[i-c]!=0:
        dp[i] = max(dp[i-c]+1,dp[i])
print(dp[n])
