#include <stdio.h>

int main()
{
    int i, j, k;
    int tmp, ans;
    int n, q;
    int a[1002][1002];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            scanf("%d", &a[i][j]);
    ans = 0;
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            ans ^= a[i][j]*a[j][i];
    scanf("%d", &q);
    while ( q-- )
    {
        scanf("%d", &k);
        if ( k == 1 )
        {
            scanf("%d", &tmp);
            ans = !ans;
        }
        else if ( k == 2 )
        {
            scanf("%d", &tmp);
            ans = !ans;
        }
        else
            printf("%d", ans);
    }
    printf("\n");
    return 0;
}
