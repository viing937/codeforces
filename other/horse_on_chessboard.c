#include <stdio.h>
#include <string.h>

#define HEI 6
#define WEI 6

int dx[8] = {-2, -1, -2, -1, +1, +2, +1, +2};
int dy[8] = {-1, -2, +1, +2, -2, -1, +2, +1};
int map[HEI][WEI];

void show()
{
    int i, j;
    for ( i = 0; i < HEI; i++ )
    {
        printf("%2d", map[i][0]);
        for ( j = 1; j < WEI; j++ )
            printf(" %2d", map[i][j]);
        printf("\n");
    }
    return;
}

int dfs(int x, int y)
{
    int i;
    if ( map[x][y] == HEI*WEI )
        return 1;
    for ( i = 0; i < 8; i++ )
    {
        if ( x+dx[i]<0 || x+dx[i]>=HEI || y+dy[i]<0 || y+dy[i]>=WEI )
            continue;
        if ( map[x+dx[i]][y+dy[i]] == 0 )
        {
            map[x+dx[i]][y+dy[i]] = map[x][y]+1;
            if ( dfs(x+dx[i], y+dy[i]) )
                return 1;
            map[x+dx[i]][y+dy[i]] = 0;
        }
    }
    return 0;
}

int main()
{
    int x, y;
    memset(map, 0, sizeof(map));
    scanf("%d%d", &x, &y);
    if ( x < 0 || x >= HEI || y < 0 || y >= WEI )
        return 0;
    map[x][y] = 1;
    dfs(x, y);
    show();
    return 0;
}
