#include <stdio.h>

int main()
{
    int i, j;
    int n, k;
    int x[200005];
    long long dp[200005] = {0};
    scanf("%d%d", &n, &k);
    for ( i = 0; i < n; i++ )
        scanf("%d", &x[i]);
    for ( i = n-1; i >= n-k; i-- )
        dp[i] = dp[i+1]+x[i];
    for ( ; i >= 0; i-- )
        dp[i] = dp[i+1]-x[i+k]+x[i];
    int a = n-k-k+1, b = n-k+1;
    for ( i = a, j = b; i >= 0; i-- )
    {
        if ( dp[i+k] >= dp[j] )
            j = i+k;
        if ( dp[i]+dp[j] >= dp[a]+dp[b] )
            a = i, b = j;
    }
    printf("%d %d\n", a+1, b+1);
    return 0;
}
