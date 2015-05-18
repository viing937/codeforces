#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int i;
    int n, m, d;
    int ans;
    int a[10005];
    int dp[2][10005];
    memset(dp, 0, sizeof(dp));
    scanf("%d%d%d", &n, &m, &d);
    for ( i = 0; i < n*m; i++ )
        scanf("%d", &a[i]);
    qsort(a, n*m, sizeof(int), cmp);
    for ( i = 1; i < n*m; i++ )
    {
        if ( (a[i]-a[i-1])%d != 0 )
        {
            printf("-1\n");
            return 0;
        }
    }
    for ( i = 1; i < n*m; i++ )
    {
        dp[0][i] = dp[0][i-1]+(a[i]-a[i-1])/d*i;
        dp[1][n*m-1-i] = dp[1][n*m-i]+(a[n*m-i]-a[n*m-1-i])/d*i;
    }
    ans = dp[0][0]+dp[1][0];
    for ( i = 0; i < n*m; i++ )
        ans = ans>dp[0][i]+dp[1][i] ? dp[0][i]+dp[1][i] : ans;
    printf("%d\n", ans);
    return 0;
}
