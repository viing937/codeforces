#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> x(n), minL(n), maxL(n);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &x[i]);
    for ( int i = 0, l = x[0], r = x[n-1]; i < n; ++i )
        maxL[i] = max(abs(x[i]-l), abs(x[i]-r));
    minL[0] = abs(x[1]-x[0]);
    for ( int i = 1, pre = x[0]; i < n; ++i )
    {
        minL[i] = abs(x[i]-pre);
        pre = x[i];
    }
    for ( int i = n-2, pre = x[n-1]; i >= 0; --i )
    {
        minL[i] = min(minL[i], abs(x[i]-pre));
        pre = x[i];
    }
    for ( int i = 0; i < n; ++i )
        printf("%d %d\n", minL[i], maxL[i]);
    return 0;
}
