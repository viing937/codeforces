#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, m, b, mod;
    scanf("%d%d%d%d", &n, &m, &b, &mod);

    int a[505];
    for ( int i = 0; i < n; ++i )
        scanf("%d", &a[i]);

    int dp[2][505][505] = {1};
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 0; j <= m; ++j )
        {
            for ( int k = 0; k <= b; ++k )
            {
                dp[i&1][j][k] = dp[(i&1)^1][j][k];
                if ( j > 0 && k >= a[i-1] )
                    dp[i&1][j][k] += dp[i&1][j-1][k-a[i-1]];
                dp[i&1][j][k] %= mod;
            }
        }
    }

    int result = 0;
    for ( int i = 0; i <= b; ++i )
        result = (result+dp[n&1][m][i])%mod;
    printf("%d\n", result);

    return 0;
}
