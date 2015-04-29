#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int length;
    char s[1005];
    char codefoeces[] = "CODEFORCES";
    scanf("%s",s);
    length = strlen(s);
    i = j = 0;
    while ( i < 10 && s[i] == codefoeces[i] )
        i++;
    while ( j < 10 && s[length-1-j] == codefoeces[9-j] )
        j++;
    if ( i+j >= 10 )
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
