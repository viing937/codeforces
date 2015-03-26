#include <stdio.h>

int main()
{
    int n, m, a;
    scanf("%d%d%d", &n, &m, &a);
    printf("%lld\n", (long long)(n/a+(n%a!=0))*(m/a+(m%a!=0)));
    return 0;
}
