#include <stdio.h>
#include <math.h>

int main()
{
    int ans = 0;
    int a, b, c;
    int n;
    scanf("%d", &n);
    for ( a = 1; a <= (int)(sqrt(2)/2*n); a++ )
    {
        for ( b = a; b <= n; b++ )
        {
            c = (int)(sqrt(a*a+b*b)+0.5);
            if ( a*a + b*b == c*c && c <= n )
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
