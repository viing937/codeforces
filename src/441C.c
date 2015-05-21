#include <stdio.h>

void move(int n, int m, int *flag, int *x, int *y)
{
    *y += *flag;
    if ( *y <= 0 )
    {
        *x += 1;
        *y = 1;
        *flag = 1;
    }
    else if ( *y > m )
    {
        *x += 1;
        *y = m;
        *flag = -1;
    }
    return;
}

int main()
{
    int i;
    int x, y;
    int flag;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    x = y = flag = 1;
    for ( i = 0; i < k-1; i++ )
    {
        printf("2");
        printf(" %d %d", x, y);
        move(n, m, &flag, &x, &y);
        printf(" %d %d\n", x, y);
        move(n, m, &flag, &x, &y);
    }
    k = n*m-2*k+2;
    printf("%d", k);
    for ( i = 0; i < k; i++ )
    {
        printf(" %d %d", x, y);
        move(n, m, &flag, &x, &y);
    }
    printf("\n");
    return 0;
}
