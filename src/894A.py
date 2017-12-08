t = "QAQ"
s = input()
dp = list(map(lambda x: 1 if x == t[0] else 0, s))
for i in range(1, len(t)):
    cnt = 0
    for j in range(0, len(dp)):
        if s[j] == t[i]:
            cnt, dp[j] = cnt+dp[j], cnt
        else:
            cnt, dp[j] = cnt+dp[j], 0
print(sum(dp))
