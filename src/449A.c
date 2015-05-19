#include <stdio.h>

int main()
{
    long long n, m, k;
    long long x, y;
    long long ans;
    scanf("%lld%lld%lld", &n, &m, &k);
    if ( n > m )
    {
        x = n;
        n = m;
        m = x;
    }
    if ( k < n )
    {
        x = 1;
        y = k+1;
        ans = (n/x)*(m/y);
        x = k+1;
        y = 1;
        if ( (n/x)*(m/y)>ans )
            ans = (n/x)*(m/y);
    }
    else if ( k >= n && k < m )
    {
        x = 1;
        y = k+1;
        ans = (n/x)*(m/y);
    }
    else if ( k >= m && k <= n+m-2 )
    {
        x = k+2-m;
        y = m;
        ans = (n/x)*(m/y);
    }
    else
    {
        ans = -1;
    }
    printf("%lld\n", ans);
    return 0;
}
