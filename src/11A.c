#include <stdio.h>

int main()
{
    int i;
    int n, d;
    int pre, cur;
    int ans = 0;
    scanf("%d%d", &n, &d);
    for ( pre = 0, i = 0; i < n; i++ )
    {
        scanf("%d", &cur);
        if ( pre >= cur )
        {
            int cnt = (pre-cur+d)/d;
            ans += cnt;
            pre = cur+cnt*d;
        }
        else
        {
            pre = cur;
        }
    }
    printf("%d\n", ans);
    return 0;
}
