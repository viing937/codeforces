#include <stdio.h>
#include <string.h>

char map[505][505];
int visited[505][505];
int n, m, k;

void dfs( int x, int y )
{
    if ( visited[x][y] == 1 )
        return;
    visited[x][y] = 1;
    if ( map[x-1][y] == '.' )
        dfs( x-1, y );
    if ( map[x+1][y] == '.' )
        dfs( x+1, y );
    if ( map[x][y-1] == '.' )
        dfs( x, y-1 );
    if ( map[x][y+1] == '.' )
        dfs( x, y+1 );
    if ( k <= 0 )
        return;
    map[x][y] = 'X';
    k--;
    return;
}

int main()
{
    int i, j;
    scanf("%d%d%d", &n, &m, &k);
    memset(map, '#', sizeof(map));
    memset(visited, 0, sizeof(visited));
    getchar();
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
            scanf("%c", &map[i][j]);
        getchar();
    }
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
            if ( map[i][j] == '.' )
                dfs(i, j);
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
            printf("%c", map[i][j]);
        printf("\n");
    }
    return 0;
}
