#include <stdio.h>

int main()
{
    int i, k;
    char s[200005];
    char ans[200005] = {0};
    k = -1;
    scanf("%s", s);
    for ( i = 0; s[i] != '\0'; i++ )
    {
        if ( k < 0 )
        {
            ans[0] = s[i];
            k = 0;
        }
        else if ( ans[k] == s[i] )
        {
            ans[k] = 0;
            k--;
        }
        else
        {
            ans[++k] = s[i];
        }
    }
    printf("%s\n", ans);
    return 0;
}
