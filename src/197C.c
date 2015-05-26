#include <stdio.h>

int main()
{
    int i;
    int len, chord, mark;
    char s[100005], ans[100005];
    scanf("%s", s);
    chord = 0;
    for ( i = 0; s[i] != '\0'; i++ )
        chord = s[i]-'a'>chord ? s[i]-'a' : chord;
    len = mark = 0;
    while ( chord >= 0 )
    {
        for ( i = mark; s[i] != '\0'; i++ )
            if ( s[i]-'a' == chord )
            {
                ans[len++] = s[i];
                mark = i;
            }
        chord--;
    }
    ans[len] = '\0';
    printf("%s\n", ans);
    return 0;
}
