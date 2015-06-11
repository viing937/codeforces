#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int len;
    char old[200005], new[200005];
    scanf("%s", old);
    len = 0;
    for ( i = 0; old[i] != '\0'; i++ )
    {
        if ( len <= 1 )
            new[len++] = old[i];
        else if ( !(new[len-1]==old[i]&&new[len-2]==old[i]) )
            new[len++] = old[i];
    }
    new[len] = '\0';
    strcpy(old, new);
    len = 0;
    for ( i = 0; old[i] != '\0'; i++ )
    {
        if ( len <= 2 )
            new[len++] = old[i];
        else if ( !(new[len-2]==new[len-3]&&new[len-1]==old[i]) )
            new[len++] = old[i];
    }
    new[len] = '\0';
    printf("%s\n", new);
    return 0;
}
