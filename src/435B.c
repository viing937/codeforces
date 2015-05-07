#include <stdio.h>

int main()
{
    int i, j;
    int index;
    int k;
    char tmpchar;
    char a[21];
    scanf("%s%d", a, &k);
    for ( i = 0; a[i] != '\0'; i++ )
    {
        index = i;
        for ( j = 0; j <= k && a[i+j] != '\0'; j++ )
            if ( a[i+j] > a[index] )
                index = i+j;
        k -= index-i;
        tmpchar = a[index];
        for ( j = index; j > i; j-- )
            a[j] = a[j-1];
        a[i] = tmpchar;
    }
    printf("%s\n", a);
    return 0;
}
