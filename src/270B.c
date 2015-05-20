#include <stdio.h>

int main()
{
    int i;
    int n;
    int a[100005];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    for ( i = n-2; i >= 0; i-- )
    {
        if ( a[i] > a[i+1] )
            break;
    }
    printf("%d\n", i+1);
    return 0;
}
