#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int n, m;
    int ans, tmp;
    int moves[100004];
    int mm[505][505];
    memset(moves, 0, sizeof(moves));
    moves[0] =  moves[1] = 1;
    for ( i = 2; i < 100004; i++ )
        if ( moves[i] == 0 )
            for ( j = i+i; j < 100004; j += i )
                moves[j] = 1;
    for ( i = 100002; i >= 0; i-- )
        if ( moves[i] != 0 )
            moves[i] = moves[i+1]+1;
    scanf("%d%d", &n, &m);
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < m; j++ )
            scanf("%d", &mm[i][j]);
    ans = 1<<30;
    for ( i = 0; i < n; i++ )
    {
        tmp = 0;
        for ( j = 0; j < m; j++ )
            tmp += moves[mm[i][j]];
        if ( tmp < ans )
            ans = tmp;
    }
    for ( i = 0; i < m; i++ )
    {
        tmp = 0;
        for ( j = 0; j < n; j++ )
            tmp += moves[mm[j][i]];
        if ( tmp < ans )
            ans = tmp;
    }
    printf("%d\n", ans);
    return 0;
}
