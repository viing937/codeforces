#include <stdio.h>

int main()
{
    int i;
    int t;
    int n;
    scanf("%d", &n);
    for ( t = 1, i = 0; i < n-1; i++ )
    {
        t = (t+i)%n+1;
        if ( i == 0 )
            printf("%d", t);
        else
            printf(" %d", t);
    }
    printf("\n");
    return 0;
}
