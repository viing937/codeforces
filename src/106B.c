#include <stdio.h>

struct Laptop
{
    int speed;
    int ram;
    int hdd;
    int cost;
};

int main()
{
    int i, j;
    int ans = -1;
    int n;
    struct Laptop laptops[105];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d%d%d%d", &laptops[i].speed, &laptops[i].ram, &laptops[i].hdd, &laptops[i].cost);
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            if ( laptops[i].speed<laptops[j].speed && laptops[i].ram<laptops[j].ram && laptops[i].hdd<laptops[j].hdd )
                break;
        }
        if ( j >= n && (laptops[i].cost < laptops[ans].cost || ans < 0) )
            ans = i;
    }
    printf("%d\n", ans+1);
    return 0;
}
