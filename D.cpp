#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, k, a;
    int m;
    scanf("%d%d%d%d", &n, &k, &a, &m);
    vector<int> x(m);
    for ( int i = 0; i < m; ++i )
        scanf("%d", &x[i]);
    int block = (n+1)/(a+1);
    vector<int> pos(n+5);
    pos[0] = n+1;
    for ( int i = 0; i < m; ++i )
    {
        if ( block < k )
        {
            printf("%d\n", i);
            return 0;
        }
        int t = 0;
        while ( x[i] > pos[t] )
            t = pos[t];
        if ( x[i] > t && x[i] < pos[t] )
        {
            block -= (pos[t]-t)/(a+1);
            block += (x[i]-t)/(a+1) + (pos[t]-x[i])/(a+1);
            pos[x[i]] = pos[t];
            pos[t] = x[i];
        }
    }
    if ( block < k )
        printf("%d\n", m);
    else
        printf("-1\n");
    return 0;
}
