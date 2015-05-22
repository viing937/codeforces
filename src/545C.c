#include <stdio.h>

struct Tree
{
    int x;
    int h;
};

int main()
{
    int i;
    int n;
    int ans, flag;
    struct Tree t[100005];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d%d", &t[i].x, &t[i].h);
    ans = 1;
    flag = 0;
    for ( i = 1; i < n; i++ )
    {
        if ( flag )
        {
            if ( t[i-1].x+t[i-1].h < t[i].x-t[i].h )
            {
                ans += 1;
                flag = 0;
            }
            else if ( t[i].x+t[i].h < t[i+1].x || i == n-1 )
            {
                ans += 1;
                flag = 1;
            }
            else
                flag = 0;
        }
        else
        {
            if ( t[i-1].x < t[i].x-t[i].h )
            {
                ans += 1;
                flag = 0;
            }
            else if ( t[i].x+t[i].h < t[i+1].x || i == n-1 )
            {
                ans += 1;
                flag = 1;
            }
            else
                flag = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
