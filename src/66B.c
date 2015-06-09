#include <stdio.h>

int main()
{
    int i;
    int n;
    int height[1005];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d", &height[i]);
    int ans = 0;
    for ( i = 0; i < n; i++ )
    {
        int cnt = 1;
        int j;
        for ( j = i; j-1 >= 0 && height[j-1] <= height[j]; j-- )
            cnt++;
        for ( j = i; j+1 < n && height[j+1] <= height[j]; j++ )
            cnt++;
        if ( cnt > ans )
            ans = cnt;
    }
    printf("%d\n", ans);
    return 0;
}
