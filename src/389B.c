#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int n;
    int ans = 1;
    char m[105][105];
    memset(m, '.', sizeof(m));
    scanf("%d", &n);
    for ( i = 1; i <= n; i++ )
        scanf("%s", m[i]+1);
    for ( i = 1; i <= n; i++ )
    {
        if ( !ans )
            break;
        for ( j = 1; j <= n; j++ )
        {
            if ( m[i][j] == '#' )
            {
                if ( m[i+1][j] == '#' && m[i+1][j-1] == '#' && m[i+1][j+1] == '#' && m[i+2][j] == '#' )
                {
                    m[i][j] = m[i+1][j] = m[i+1][j-1] = m[i+1][j+1] = m[i+2][j] = '.';
                }
                else
                {
                    ans = 0;
                    break;
                }   
            }
        }
    }
    if ( ans )
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
