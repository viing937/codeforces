#include <stdio.h>
#include <string.h>

int n, m, k;
long long p[5005];
long long dp[5005][5005];

int main()
{
    int i, j;
    memset(p, 0, sizeof(p));
    memset(dp, 0, sizeof(dp));
    scanf("%d%d%d", &n, &m, &k);
    for ( i = 1; i <= n; i++ )
        scanf("%lld", &p[i]);
    for ( i = 1; i <= n; i++ )
        p[i] += p[i-1];
    for ( i = m; i <= n; i++ )
    {
        for ( j = 1; j <= k; j++ )
        {
            if ( dp[i-1][j] > dp[i-m][j-1]+p[i]-p[i-m] )
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-m][j-1]+p[i]-p[i-m];
        }
    }
    printf("%lld\n", dp[n][k]);
    return 0;
}
