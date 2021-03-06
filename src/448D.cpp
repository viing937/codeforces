#include <iostream>
using namespace std;

int main()
{
    long long n, m, k, l, r, mid, t;
    cin >> n >> m >> k;
    l = 1, r = n*m+1;
    while ( l < r )
    {
        mid = (l+r)/2;
        t = 0;
        for ( long long i = 1; i <= n; ++i )
            t += min(m, (mid-1)/i);
        if ( t < k )
            l = mid+1;
        else
            r = mid;
    }
    cout << l-1 << endl;
    return 0;
}
