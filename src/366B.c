#include <stdio.h>

int main()
{
    int i;
    int n, k;
    int s[100005] = {0};
    scanf("%d%d", &n, &k);
    for ( i = 0; i < n; i++ )
    {
        int tmp;
        scanf("%d", &tmp);
        s[i%k] += tmp;
    }
    int ans = 0;
    for ( i = 0; i < k; i++ )
    {
        if ( s[i] < s[ans] )
            ans = i;
    }
    printf("%d\n", ans+1);
    return 0;
}
