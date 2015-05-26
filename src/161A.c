#include <stdio.h>

int main()
{
    int i, j;
    int n, m, x, y;
    int a[100005], b[100005];
    int u[100005], v[100005];
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for ( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    for ( i = 0; i < m; i++ )
        scanf("%d", &b[i]);
    int ans = 0;
    i = j = 0;
    while ( i < n && j < m )
    {
        if ( a[i]-x > b[j] )
            j++;
        else if ( a[i]+y < b[j] )
            i++;
        else
        {
            u[ans] = ++i;
            v[ans++] = ++j;
        }
    }
    printf("%d\n", ans);
    for ( i = 0; i < ans; i++ )
        printf("%d %d\n", u[i], v[i]);
    return 0;
}
