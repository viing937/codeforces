#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int main()
{
    int i, j;
    int n, k, d;
    int dp[105];
    int tt[105];
    memset(dp, 0, sizeof(dp));
    memset(tt, 0, sizeof(tt));
    scanf("%d%d%d", &n, &k, &d);
    for ( tt[0] = 1, i = 1; i < 105; i++ )
        for ( j = 1; j <= i && j <= k; j++ )
            tt[i] = (tt[i]+tt[i-j])%MOD;
    for ( i = d; i <= n; i++ )
    {
        for ( j = 1; j < d; j++ )
            dp[i] = (dp[i]+dp[i-j])%MOD;
        for ( j = d; j <= i && j <= k; j++ )
            dp[i] = (dp[i]+tt[i-j])%MOD;
    }
    printf("%d\n", dp[n]);
    return 0;
}
