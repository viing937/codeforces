#include <stdio.h>
#include <math.h>

int main()
{
    int ans;
    int x, y;
    int a, b;
    scanf("%d%d", &a, &b);
    a -= b;
    if ( a == 0 )
        printf("infinity\n");
    else if ( a < 0 )
        printf("0\n");
    else
    {
        ans = 0;
        for ( x = 1; x <= (int)sqrt(a); x++ )
        {
            if ( a%x!=0 )
                continue;
            y = a/x;
            if ( x > b )
                ans++;
            if ( y != x && y > b )
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
