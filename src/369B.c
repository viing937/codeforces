#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    int ans[1005];
    int n, k, l, r, sall, sk;
    scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sall, &sk);
    for ( i = 0; i < k; i++ )
        ans[i] = sk/k;
    if ( sk%k != 0 )
    {
        for ( i = 0; i < sk%k; i++ )
            ans[i]++;
    }
    if ( n != k )
    {
        for ( i = k; i < n; i++ )
            ans[i] = (sall-sk)/(n-k);
        if ( (sall-sk)/(n-k) != 0 )
        {
            for ( i = 0; i < (sall-sk)%(n-k); i++ )
                ans[k+i]++;
        }
    }
    printf("%d", ans[0]);
    for ( i = 1; i < n; i++ )
        printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
