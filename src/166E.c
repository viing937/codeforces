#include <stdio.h>
#define MOD 1000000007

int main()
{
    int a, b, c, d;
    int aa, bb, cc, dd;
    int n;
    scanf("%d", &n);
    a = b = c = 1;
    d = 0;
    while ( --n )
    {
        aa = ((b+c)%MOD+d)%MOD;
        bb = ((a+c)%MOD+d)%MOD;
        cc = ((a+b)%MOD+d)%MOD;
        dd = ((a+b)%MOD+c)%MOD;
        a = aa, b = bb, c = cc, d = dd;
    }
    printf("%d\n", d);
    return 0;
}
