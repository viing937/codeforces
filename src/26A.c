#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int i, j;
    int n, cnt, ans = 0;
    int isprime[3005];
    scanf("%d", &n);
    memset(isprime, 0, sizeof(isprime));
    isprime[0] = isprime[1] = 1;
    for ( i = 2; i <= n; i++ )
        if ( isprime[i] == 0 )
            for ( j = i+i; j <= n; j+=i )
                isprime[j] = 1;
    for ( i = 1; i <= n; i++ )
    {
        cnt = 0;
        for ( j = 1; j <= (int)sqrt(i); j++ )
        {
            if ( i%j )
                continue;
            if ( isprime[j] == 0 )
                cnt++;
            if ( i/j != j && isprime[i/j] == 0 )
                cnt++;
        }
        if ( cnt == 2 )
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
