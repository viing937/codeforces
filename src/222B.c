#include <stdio.h>

int main()
{
    int i, j;
    int swaptmp;
    int n, m, k;
    char s[2];
    int p[1005][1005];
    int indexx[1005], indexy[1005];
    scanf("%d%d%d", &n, &m, &k);
    for ( i = 0; i < n; i++ )
        indexx[i] = i;
    for ( i = 0; i < m; i++ )
        indexy[i] = i;
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < m; j++ )
            scanf("%d", &p[i][j]);
    while ( k-- )
    {
        scanf("%s%d%d", s, &i, &j);
        i -= 1;
        j -= 1;
        if ( s[0] == 'c' )
        {
            swaptmp = indexy[i];
            indexy[i] = indexy[j];
            indexy[j] = swaptmp;
        }
        else if ( s[0] == 'r' )
        {
            swaptmp = indexx[i];
            indexx[i] = indexx[j];
            indexx[j] = swaptmp;
        }
        else
            printf("%d\n", p[indexx[i]][indexy[j]]);
    }
    return 0;
}
