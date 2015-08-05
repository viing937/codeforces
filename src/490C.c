#include <stdio.h>
#include <string.h>
#define MAXN 1000000

int rema[MAXN+5], remb[MAXN+5];
char s[MAXN+5];

int main()
{
    int i, j;
    int a, b;
    int len;
    scanf("%s%d%d", s, &a, &b);
    len = strlen(s);

    rema[0] = (s[0]-'0')%a;
    for ( i = 1; i < len; ++i )
        rema[i] = (rema[i-1]*10+s[i]-'0')%a;

    remb[len-1] = (s[i-1]-'0')%b;
    int p = 10;
    for ( i = len-2; i >= 0; --i )
    {
        remb[i] = ((s[i]-'0')*p+remb[i+1])%b;
        p = p*10%b;
    }

    for ( i = 1; i < len; ++i )
    {
        if ( s[0] != '0' && s[i] != '0' && rema[i-1] == 0 && remb[i] == 0 )
        {
            printf("YES\n");
            j = 0;
            while ( j < i )
                printf("%c", s[j++]);
            printf("\n");
            while ( j < len )
                printf("%c", s[j++]);
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
