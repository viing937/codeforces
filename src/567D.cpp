#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int cal(int l, int r, int a)
{
    return (r-l+2)/(a+1);
}

int main()
{
    int n, k, a;
    scanf("%d%d%d", &n, &k, &a);
    int m;
    scanf("%d", &m);
    set< pair<int, int> > segments;
    int ships = cal(1, n, a);
    segments.insert(make_pair(n, 1));
    for ( int i = 0; i < m; ++i )
    {
        int x;
        scanf("%d", &x);

        auto it = segments.lower_bound(make_pair(x, -1));
        int l = it->second, r = it->first;
        segments.erase(it);

        ships -= cal(l, r, a);
        if ( l <= x-1 )
        {
            ships += cal(l, x-1, a);
            segments.insert(make_pair(x-1, l));
        }
        if ( x+1 <= r )
        {
            ships += cal(x+1, r, a);
            segments.insert(make_pair(r, x+1));
        }
        if ( ships < k )
        {
            printf("%d\n", i+1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
