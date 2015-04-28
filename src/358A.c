#include <stdio.h>

int main()
{
    int i, j;
    int n;
    int x1, x2, x3, x4;
    int x[1005];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d", &x[i]);
    for ( i = 0; i < n-1; i++ )
    {
        for ( j = i+1; j < n-1; j++ )
        {
            x1 = x[i]<x[i+1] ? x[i] : x[i+1];
            x2 = x[i]>x[i+1] ? x[i] : x[i+1];
            x3 = x[j]<x[j+1] ? x[j] : x[j+1];
            x4 = x[j]>x[j+1] ? x[j] : x[j+1];
            if ( (x1 < x3 && x3 < x2 && x2 < x4) || (x3 < x1 && x1 < x4 && x4 < x2) )
            {
                printf("yes\n");
                return 0;
            }
        }
    }
    printf("no\n");
    return 0;
}
