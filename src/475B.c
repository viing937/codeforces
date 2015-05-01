#include <stdio.h>
#include <string.h>

int n, m;
int graph[405][405];

void floyd()
{
    int i, j, k;
    for ( k = 0; k < n*m; k++ )
        for ( i = 0; i < n*m; i++ )
            for ( j = 0; j < n*m; j++ )
                if ( graph[i][k] && graph[k][j] )
                    graph[i][j] = 1;
    return;
}

int main()
{
    int i, j, k;
    char tmp[25];
    memset(graph, 0, sizeof(graph));
    scanf("%d%d", &n, &m);
    scanf("%s", tmp);
    for ( i = 0; i < n; i++ )
    {
        if ( tmp[i] == '>' )
            for ( j = 0; j < m; j++ )
                for ( k = j; k < m; k++ )
                    graph[i*m+j][i*m+k] = 1;
        else
            for ( j = m-1; j >= 0; j-- )
                for ( k = j; k >= 0; k-- )
                    graph[i*m+j][i*m+k] = 1;
    }
    scanf("%s", tmp);
    for ( i = 0; i < m; i++ )
    {
        if ( tmp[i] == 'v' )
            for ( j = 0; j < n; j++ )
                for ( k = j; k < n; k++ )
                    graph[i+j*m][i+k*m] = 1;
        else
            for ( j = n-1; j >= 0; j-- )
                for ( k = j; k >= 0; k-- )
                    graph[i+j*m][i+k*m] = 1;
    }
    floyd();
    for ( i = 0; i < n*m; i++ )
    {
        for ( j = 0; j < n*m; j++ )
        {
            if ( graph[i][j] == 0 )
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
