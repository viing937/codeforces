#include <stdio.h>
#include <string.h>

int n, m;
int dx[] = {+1,0,0,-1};
int dy[] = {0,+1,-1,0};
int visited[55][55];
char graph[55][55];

int dfs(int x, int y, int dir)
{
    int i;
    int result = 0;
    if ( visited[x][y] )
        return 1;
    visited[x][y] = 1;
    for ( i = 0; i < 4; i++ )
    {
        if ( i != dir && graph[x][y] == graph[x+dx[i]][y+dy[i]] )
        {
            result = result || dfs(x+dx[i], y+dy[i], 3-i);
        }
    }
    return result;
}

int main()
{
    int i, j;
    memset(visited, 0, sizeof(visited));
    memset(graph, 0, sizeof(graph));
    scanf("%d%d", &n, &m);
    getchar();
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
            scanf("%c", &graph[i][j]);
        getchar();
    }
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            if ( visited[i][j] == 0 && dfs(i,j,-1) )
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
