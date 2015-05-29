#include <stdio.h>
#include <math.h>

#define MOD 1073741824

int cal(int k)
{
    int i;
    int result = 0;
    for ( i = 1; i <= sqrt(k); i++ )
    {
        if ( k%i )
            continue;
        result += 1;
        if ( k/i != i )
            result += 1;
    }
    return result;
}

int main()
{
    int i,  j, k;
    int a, b, c;
    int cnt[1000005] = {0};
    int ans = 0;
    scanf("%d%d%d", &a, &b, &c);
    for ( i = 1; i <= a; i++ )
    {
        for ( j = 1; j <= b; j++ )
        {
            for ( k = 1; k <= c; k++ )
            {
                if ( cnt[i*j*k] == 0 )
                    cnt[i*j*k] = cal(i*j*k);
                ans = (ans+cnt[i*j*k])%MOD;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
