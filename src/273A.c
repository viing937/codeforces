#include <stdio.h>

int main()
{
    int i;
    int n, m;
    int w, h;
    long long a[100005];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%lld", &a[i]);
    scanf("%d", &m);
    while ( m-- )
    {
        scanf("%d%d", &w, &h);
        if ( a[0] >= a[w-1] )
        {
            printf("%lld\n", a[0]);
            a[0] += h;
        }
        else
        {
            printf("%lld\n", a[w-1]);
            a[0] = a[w-1]+h;
        }
    }
    return 0;
}
