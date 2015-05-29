#include <stdio.h>

int main()
{
    int i, j;
    int n;
    int arr[105];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d", &arr[i]);
    int ans = arr[0];
    for ( i = 0; i < n; i++ )
    {
        int tmp = arr[i];
        if ( tmp > ans )
            ans = tmp;
        for ( j = i+1; j < n; j++ )
        {
            tmp ^= arr[j];
            if ( tmp > ans )
                ans = tmp;
        }
    }
    printf("%d\n", ans);
    return 0;
}
