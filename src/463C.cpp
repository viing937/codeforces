#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector< vector<int> > a(n, vector<int>(n));
    vector<long long> d1(2*n-1, 0), d2(2*n-1, 0);
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < n; ++j )
        {
            scanf("%d", &a[i][j]);
            d1[i+j] += a[i][j];
            d2[i-j+n-1] += a[i][j];
        }
    }
    vector<long long> ans(2, -1);
    vector<int> x(2), y(2);
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < n; ++j )
        {
            int c = (i+j)%2;
            long long sum = d1[i+j]+d2[i-j+n-1]-a[i][j];
            if ( sum > ans[c] )
            {
                x[c] = i, y[c] = j;
                ans[c] = sum;
            }
        }
    }
    printf("%I64d\n", ans[0]+ans[1]);
    printf("%d %d %d %d\n", x[0]+1, y[0]+1, x[1]+1, y[1]+1);
    return 0;
}
