#include <stdio.h>

int main()
{
    int x, y, k, n;
    int flag = 1;
    scanf("%d%d%d", &y, &k, &n );
    x = k-y%k;
    while ( x+y <= n )
    {
        if ( flag )
        {
            printf("%d", x);
            flag = 0;
        }
        else
            printf(" %d", x);
        x += k;
    }
    if ( flag )
        printf("-1\n");
    else
        printf("\n");
    return 0;
}
