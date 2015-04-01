#include <stdio.h>

int p[2005];
int height[2005];

int calheight(int a)
{
    if ( height[a] > 0 )
        return height[a];
    else if ( p[a] == -1 )
        return height[a] = 1;
    else
        return height[a] = calheight(p[a])+1;
}

int main()
{
    int i, tmp;
    int n, ans = -1;
    scanf("%d",&n);
    for ( i = 1; i <= n; i++ )
        scanf("%d",&p[i]);
    for ( i = 1; i <= n; i++ )
    {
        tmp = calheight(i);
        if ( tmp > ans )
            ans = tmp;
    }
    printf("%d\n", ans);
    return 0;
}
