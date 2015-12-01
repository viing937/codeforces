#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, l, r, Ql, Qr;
    cin >> n >> l >> r >> Ql >> Qr;
    vector<int> w(n);
    cin >> w[0];
    for ( int i = 1; i < n; ++i )
    {
        cin >> w[i];
        w[i] += w[i-1];
    }
    int ans = w[n-1]*r + (n-1)*Qr;
    for ( int i = 1; i <= n; ++i )
    {
        int curr = w[i-1]*l + (w[n-1]-w[i-1])*r;
        if ( i > n-i )
            curr += (2*i-n-1)*Ql;
        if ( i < n-i )
            curr += (n-2*i-1)*Qr;
        ans = min(ans, curr);
    }
    cout << ans << endl;
    return 0;
}
