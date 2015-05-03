#include <stdio.h>

int main()
{
    int i;
    int n;
    int ans;
    char s[30005][22];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%s", s[i]);
    ans = 0;
    while ( s[0][ans] != '\0' )
    {
        for ( i = 0; i < n; i++ )
            if ( s[i][ans] != s[0][ans] )
            {
                printf("%d\n", ans);
                return 0;
            }
        ans++;
    }
    return 0;
}
