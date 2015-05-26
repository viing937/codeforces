#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int n;
    int ans;
    int a[1005], b[1005], cnt[1005];
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
    {
        scanf("%d%d", &a[i], &b[i]);
        cnt[b[i]] += 1;
    }
    ans = 0;
    for ( i = 0; i < n; i++ )
        if ( cnt[a[i]] - (a[i]==b[i]?1:0) <= 0 )
            ans++;
    printf("%d\n", ans);
    return 0;
}
