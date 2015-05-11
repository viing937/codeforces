#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int i, j;
    int ans;
    int n;
    int s[500005];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d", &s[i]);
    qsort(s, n, sizeof(int), cmp);
    ans = 0;
    i = 0, j = n/2;
    while ( i < n/2 )
    {
        while ( j+1 < n && s[i]*2 > s[j] )
            j++;
        if ( j < n && s[j] != -1 && s[i]*2 <= s[j] )
        {
            s[i] = s[j] = -1;
            ans++;
        }
        i++;
    }
    for ( i = 0; i < n; i++ )
        if ( s[i] != -1 )
            ans++;
    printf("%d\n", ans);
    return 0;
}
