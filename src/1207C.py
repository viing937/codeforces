inf = float("inf")

T = int(input())
for _ in range(T):
    n, a, b = map(int, input().split())
    s = list(map(int, input()))
    dp = [b, inf]
    for i in range(n):
        if s[i]:
            dp[0], dp[1] = inf, dp[1] + a + 2 * b
        else:
            dp[0], dp[1] = (
                min(dp[0] + a + b, dp[1] + 2 * a + b),
                min(dp[0] + 2 * a + 2 * b, dp[1] + a + 2 * b),
            )
    print(dp[0])
