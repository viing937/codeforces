#include <stdio.h>

void fill(int a, int b, int c, int color[])
{
    int i;
    for ( i = 1; i <= 3; i++ )
    {
        if ( color[a]!=i && color[b]!=i && color[c]!=i )
        {
            if ( color[a] == 0 )
                color[a] = i;
            else if ( color[b] == 0 )
                color[b] = i;
            else
                color[c] = i;
        }
    }
    return;
}

int main()
{
    int i;
    int n, m;
    int color[100005] = {0};
    scanf("%d%d",&n, &m);
    for ( i = 0; i < m; i++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        fill(a, b, c, color);
    }
    printf("%d", color[1]);
    for ( i = 2; i <= n; i++ )
        printf(" %d", color[i]);
    printf("\n");
    return 0;
}
