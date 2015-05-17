#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int k;
    int length;
    char s[100005];
    char t[100005];
    scanf("%s", s);
    length = strlen(s);
    if ( length%2 )
    {
        printf("No\n");
        return 0;
    }
    k = 0;
    for ( i = 0; i < length; i++ )
    {
        if ( k == 0 || s[i] != t[k-1] )
        {
            t[k] = s[i];
            k++;
        }
        else
        {
            k--;
        }
    }
    if ( k <= 0 )
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
