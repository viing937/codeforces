#include <stdio.h>

int main()
{
    long long x, y, m;
    long long ans = 0;
    long long tmp;
    scanf("%lld%lld%lld", &x, &y, &m);
    if ( x > y )
    {
        tmp = x;
        x = y;
        y = tmp;
    }
    if ( y >= m )
    {
        printf("0\n");
        return 0;
    }
    if ( x <= 0 && y <= 0 )
    {
        printf("-1\n");
        return 0;
    }
    if ( x < 0 )
    {
        ans += -x/y+1;
        x += ans*y; 
    }
    while ( y < m )
    {
        ans++;
        tmp = x+y;
        x = y;
        y = tmp;
    }
    printf("%lld\n", ans);
    return 0;
}
