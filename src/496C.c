#include <stdio.h>
#include <string.h>

int main()
{
    int flag;
    int i, j;
    int n, m;
    int ans = 0;
    int mark[105];
    char str[105][105];
    memset(mark, 0, sizeof(mark));
    scanf("%d%d", &n, &m);
    for ( i = 0; i < n; i++ )
        scanf("%s", str[i]);
    for ( i = 0; i < m; i++ )
    {
        flag = 0;
        for ( j = 0; j < n-1; j++ )
        {
            if ( mark[j] )
                continue;
            else if ( str[j][i] > str[j+1][i] )
            {
                ans += 1;
                flag = 1;
                break;
            }
        }
        if ( !flag )
        {
            for ( j = 0; j < n-1; j++ )
                if ( str[j][i] < str[j+1][i] )
                    mark[j] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
