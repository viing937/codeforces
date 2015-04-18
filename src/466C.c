#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    long long sum, avg, ans;
    int n;
    int a[500005];
    long long cnt[500005];
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    avg = 0;
    for ( i = 0; i < n; i++ )
    {
        scanf("%d", &a[i]);
        avg += a[i];
    }
    if ( avg%3 != 0 )
    {
        printf("0\n");
        return 0;
    }
    avg /= 3;
    sum = 0;
    for ( i = n-1; i >= 0; i-- )
    {
        cnt[i] += cnt[i+1];
        sum += a[i];
        if ( sum == avg )
            cnt[i] += 1;
    }
    sum = 0, ans = 0;
    for ( i = 0; i < n; i++ )
    {
        sum += a[i];
        if ( sum == avg )
            ans += cnt[i+2];
    }
    printf("%lld\n", ans);
    return 0;
}
