#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<long long> x(n), y(n);
    for ( int i = 0; i < n; ++i )
        cin >> x[i] >> y[i];
    long long ans = 0xffffffffffffff;
    for ( int i = 0; i <= n; ++i )
    {
        long long r1, r2;
        if ( i < n )
            r1 = (x[i]-x1)*(x[i]-x1)+(y[i]-y1)*(y[i]-y1);
        else
            r1 = 0;
        r2 = 0;
        for ( int j = 0; j < n; ++j )
        {
            long long d1 = (x[j]-x1)*(x[j]-x1)+(y[j]-y1)*(y[j]-y1),
                      d2 = (x[j]-x2)*(x[j]-x2)+(y[j]-y2)*(y[j]-y2);
            if ( d1 > r1 )
                r2 = max(r2, d2);
        }
        ans = min(ans, r1+r2);
    }
    cout << ans << endl;
    return 0;
}
