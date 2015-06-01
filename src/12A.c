#include <stdio.h>

int main()
{
    char s[3][4];
    scanf("%s%s%s", s[0], s[1], s[2]);
    if ( s[0][0]==s[2][2] && s[0][1]==s[2][1] && s[0][2]==s[2][0] && s[1][0]==s[1][2] )
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
