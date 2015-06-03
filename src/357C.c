#include <stdio.h>

int getnext(int x, int next[])
{
    if ( next[x] == 0 )
        return x;
    else
        return next[x] = getnext(next[x], next);
}

int main()
{
    int i;
    int n, m;
    int ans[300005], next[300005] = {0};
    scanf("%d%d", &n, &m);
    while ( m-- )
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        int cur = getnext(l, next);
        while ( cur <= r )
        {
            if ( cur == x )
                cur += 1;
            else
            {
                ans[cur] = x;
                next[cur] = cur+1;
            }
            cur = getnext(cur, next);
        }
    }
    printf("%d", ans[1]);
    for ( i = 2; i <= n; i++ )
        printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
