#include <stdio.h>

int main()
{
    int i;
    int n, ans = 1;
    int a[100005];
    int l[100005], r[100005];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    for ( l[0] = 1, i = 1; i < n; i++ )
    {
        if ( a[i] > a[i-1] )
            l[i] = l[i-1]+1;
        else
            l[i] = 1;
        ans = ans>l[i]+1 ? ans : l[i]+1;
    }
    for ( r[n-1] = 1, i = n-1; i >= 0; i-- )
    {
        if ( a[i] < a[i+1] )
            r[i] = r[i+1]+1;
        else
            r[i] = 1;
        ans = ans>r[i]+1 ? ans : r[i]+1;
    }
    for ( i = 1; i < n-1; i++ )
    {
        if ( a[i-1]+1 < a[i+1] && ans < l[i-1]+r[i+1]+1 )
            ans = l[i-1]+r[i+1]+1;
    }
    printf("%d\n", ans<n? ans : n);
    return 0;
}
