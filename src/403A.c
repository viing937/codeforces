#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while ( t-- )
    {
        int n, p;
        scanf("%d%d", &n, &p);
        int cnt = 2*n+p;
        int i, j;
        for ( i = 1; i <= n && cnt > 0; i++ )
        {
            for ( j = i+1; j <= n && cnt > 0; j++ )
            {
                printf("%d %d\n", i, j);
                cnt -= 1;
            }
        }
    }
    return 0;
}
