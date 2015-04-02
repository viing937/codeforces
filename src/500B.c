#include <stdio.h>

int main()
{
    int i, j, k, tmp;
    int n;
    int p[305];
    char a[305][305];
    scanf("%d",&n);
    for ( i = 0; i < n; i++ )
        scanf("%d",&p[i]);
    for ( i = 0; i < n; i++ )
        scanf("%s",a[i]);
    for ( k = 0; k < n; k++ )
        for ( i = 0; i < n; i++ )
            for ( j = 0; j < n; j++ )
                if ( a[i][k]=='1' && a[k][j]=='1' )
                    a[i][j] = '1';
    for ( i = 0; i < n; i++ )
        for ( j = i+1; j < n; j++ )
            if ( a[i][j]=='1' && p[i]>p[j] )
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
    printf("%d",p[0]);
    for ( i = 1; i < n; i++ )
        printf(" %d",p[i]);
    printf("\n");
    return 0;
}
