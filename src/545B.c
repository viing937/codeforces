#include <stdio.h>

int main()
{
    int i;
    int cnt;
    char s[100005], t[100005];
    scanf("%s%s", s, t);
    cnt = 0;
    for ( i = 0; s[i] != '\0'; i++ )
        if ( s[i] != t[i] )
            cnt++;
    if ( cnt%2 )
        printf("impossible\n");
    else
    {
        cnt /= 2;
        for ( i = 0; s[i] != '\0'; i++ )
        {
            if ( s[i] == t[i] )
                printf("%c", s[i]);
            else
            {
                if ( cnt )
                {
                    printf("%c", s[i]);
                    cnt--;
                }
                else
                {
                    printf("%c", t[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
