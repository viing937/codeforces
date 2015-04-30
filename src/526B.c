#include <stdio.h>
#include <string.h>

int n;
int ans;
int a[1<<12];

void dfs(int root)
{
    if ( root > 1<<n )
        return;
    dfs(root*2);
    dfs(root*2+1);
    if ( a[root*2] > a[root*2+1] )
    {
        ans += a[root*2]-a[root*2+1];
        a[root] += a[root*2];
    }
    else
    {
        ans += a[root*2+1]-a[root*2];
        a[root] += a[root*2+1];
    }
    return;
}

int main()
{
    int i;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    ans = 0;
    for ( i = 2; i < 2<<n; i++ )
        scanf("%d", &a[i]);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
