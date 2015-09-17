#include <cstdio>
#include <vector>
#define MAXN 131072
using namespace std;

vector<int> segtree(MAXN<<1, 0);

void update(int i, int a)
{
    i += MAXN;
    segtree[i] = a;
    i /= 2;
    int count = 0;
    while ( i )
    {
        if ( count%2 )
            segtree[i] = segtree[i*2]^segtree[i*2+1];
        else
            segtree[i] = segtree[i*2]|segtree[i*2+1];
        i /= 2;
        count += 1;
    }
    return;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for ( int i = 0; i < (1<<n); ++i )
    {
        int a;
        scanf("%d", &a);
        update(i, a);
    }
    for ( int i = 0; i < m; ++i )
    {
        int p, b;
        scanf("%d%d", &p, &b);
        update(p-1, b);
        printf("%d\n", segtree[1]);
    }
    return 0;
}
