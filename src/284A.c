#include <stdio.h>

int check(int p, int x)
{
    int i;
    int pow = 1;
    for ( i = 0; i < p-2; i++ )
    {
        pow = (pow*x)%p;
        if ( pow == 1 )
            return 0;
    }
    pow = (pow*x)%p;
    if ( pow == 1 )
        return 1;
    else
        return 0;
}

int main()
{
    int i;
    int p;
    int ans;
    scanf("%d", &p);
    ans = 0;
    for ( i = 1; i < p; i++ )
        ans += check(p, i);
    printf("%d\n", ans);
    return 0;
}
