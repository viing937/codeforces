#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int m, n;
    int t[50005][10];
    memset(t, 0, sizeof(t));
    scanf("%d%d", &m, &n);
    for ( i = 1; i <= m; i++ )
        for ( j = 1; j <= n; j++ )
            scanf("%d", &t[i][j]);
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
            t[j][i] += t[j-1][i]>t[j][i-1] ? t[j-1][i] : t[j][i-1];
    printf("%d", t[1][n]);
    for ( i = 2; i <= m; i++ )
        printf(" %d", t[i][n]);
    printf("\n");
    return 0;
}
