#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i];
    vector<int> dp;
    for ( int i = 1; i < n; ++i )
        dp.push_back(a[i]-a[i-1]);

    int last = 0;
    while ( last < n-1 && dp[last] == 0 )
        last += 1;
    if ( last == n-1 )
    {
        cout << n << endl;
        return 0;
    }

    int ans = last+2, len = last+2;
    for ( int i = last+1; i < n-1; ++i )
    {
        if ( dp[i] == 0 )
            len += 1;
        else if ( dp[i] != dp[last] )
        {
            len += 1;
            last = i;
        }
        else
        {
            len = i-last+1;
            last = i;
        }
        ans = max(ans, len);
    }
    cout << ans << endl;
    return 0;
}
