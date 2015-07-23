#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXLEN 200000

bool strEqual(char *a, char *b, int len)
{
    int i;
    for ( i = 0; i < len; i++ )
        if ( a[i] != b[i] )
            return false;
    return true;
}

bool equal(char *a, char *b, int len)
{
    if ( strEqual(a, b, len) )
        return true;
    else if ( len % 2 == 0 )
    {
        char *a1 = a, *a2 = a+len/2;
        char *b1 = b, *b2 = b+len/2;
        return (equal(a1, b1, len/2) && equal(a2, b2, len/2)) || (equal(a1, b2, len/2) && equal(a2, b1, len/2));
    }
    else
        return false;
}

int main()
{
    char a[MAXLEN+5], b[MAXLEN+5];
    scanf("%s%s", a, b);
    int lenA = strlen(a), lenB = strlen(b);
    if ( lenA == lenB && equal(a, b, lenA) )
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
