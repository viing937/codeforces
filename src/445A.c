#include <stdio.h>
char mm[102][102];
char c[] = {'B','W'};

void dfs(int i, int j, int flag)
{
    mm[i][j] = c[flag];
    if ( mm[i-1][j] == '.' )
        dfs(i-1, j, 1-flag);
    if ( mm[i+1][j] == '.' )
        dfs(i+1, j, 1-flag);
    if ( mm[i][j-1] == '.' )
        dfs(i, j-1, 1-flag);
    if ( mm[i][j+1] == '.' )
        dfs(i, j+1, 1-flag);
    return;
}

int main()
{
    int i, j;
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
            scanf("%c",&mm[i][j]);
        getchar();
    }
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
            if ( mm[i][j] == '.' )
                dfs(i, j, 0);
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
            printf("%c", mm[i][j]);
        printf("\n");
    }
    return 0;
}
