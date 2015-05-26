#include <stdio.h>
#include <string.h>

int count(int i, int j, char s[][2005], int n, int m)
{
    int result = 0;
    if ( j-i >= 0 && s[i][j-i] == 'R' )
        result++;
    if ( j+i < m && s[i][j+i] == 'L' )
        result++;
    if ( i+i < n && s[i+i][j] == 'U' )
        result++;
    return result;
}

int main()
{
    int i, j;
    int n, m, k;
    int ans[2005];
    char s[2005][2005];
    memset(ans, 0, sizeof(ans));
    scanf("%d%d%d", &n, &m, &k);
    for ( i = 0; i < n; i++ )
        scanf("%s", s[i]);
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < m; j++ )
        {
            ans[j] += count(i, j, s, n, m);
        }
    }
    printf("%d", ans[0]);
    for ( i = 1; i < m; i++ )
        printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
