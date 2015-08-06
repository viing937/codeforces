#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> cnt(n+1, 0);
    for ( int i = 0; i < m; i++ )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        cnt[x] += 1;
        cnt[y] += 1;
    }
    if ( n == m+1 )
    {
        if ( count(cnt.begin(), cnt.end(), 1) == 2 && count(cnt.begin(), cnt.end(), 2) == n-2 )
            printf("bus topology\n");
        else if ( count(cnt.begin(), cnt.end(), 1) == n-1 )
            printf("star topology\n");
        else
            printf("unknown topology\n");
    }
    else if ( n == m )
    {
        if ( count(cnt.begin(), cnt.end(), 2) == n )
            printf("ring topology\n");
        else
            printf("unknown topology\n");
    }
    else
        printf("unknown topology\n");
    return 0;
}
