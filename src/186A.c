#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int length;
    char tmp;
    char a[100005], b[100005];
    scanf("%s%s", a, b);
    length = strlen(a);
    if ( length != strlen(b) )
    {
        printf("NO\n");
        return 0;
    }
    for ( i = 0; i < length; i++ )
        if ( a[i] != b[i] )
            break;
    for ( j = i+1; j < length; j++ )
        if ( a[j] != b[j] )
            break;
    if ( i >= length || j >= length )
    {
        printf("NO\n");
        return 0;
    }
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    if ( strcmp(a,b) == 0 )
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
