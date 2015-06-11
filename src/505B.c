#include <stdio.h>

int n, m, q;
int map[101][101][101];

void floyd(int t)
{
    int i, j, k;
    for ( k = 1; k <= n; k++ )
        for ( i = 1; i <= n; i++ )
            for ( j = 1; j <= n; j++ )
                if ( map[t][i][k] && map[t][k][j] )
                    map[t][i][j] = 1;
}

int main()
{
    int i, j;
    scanf("%d%d", &n, &m);
    for ( i = 1; i <= m; i++ )
        for ( j = 1; j <= n; j++ )
            map[i][j][j] = 1;
    for ( i = 0; i < m; i++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        map[c][a][b] = 1;
        map[c][b][a] = 1;
    }
    for ( i = 1; i <= m; i++ )
        floyd(i);
    scanf("%d", &q);
    while ( q-- )
    {
        int ans = 0;
        int u, v;
        scanf("%d%d", &u, &v);
        for ( i = 1; i <= m; i++ )
            ans += map[i][u][v];
        printf("%d\n", ans);
    }
    return 0;
}
