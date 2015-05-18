#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int n;
    int tmp;
    int a[3005];
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
    {
        scanf("%d", &tmp);
        a[tmp] = 1;
    }
    for ( i = 1; i < 3005; i++ )
    {
        if ( !a[i] )
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
