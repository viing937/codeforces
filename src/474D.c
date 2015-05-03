#include <stdio.h>
#define MOD 1000000007
int main()
{
    int i;
    int t, k;
    int a, b;
    int dp[100005];
    scanf("%d%d", &t, &k);
    for ( i = 0; i < k; i++ )
        dp[i] = 1;
    for ( i = k; i <= 100000; i++ )
        dp[i] = (dp[i-1]+dp[i-k])%MOD;
    for ( i = 1; i <= 100000; i++ )
        dp[i] = (dp[i]+dp[i-1])%MOD;
    for ( i = 0; i < t; i++ )
    {
        scanf("%d%d", &a, &b );
        printf("%d\n", (dp[b]-dp[a-1]+MOD)%MOD);
    }
    return 0;
}
