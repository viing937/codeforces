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

    if ( n == 1 && a[0] == 1 )
    {
        cout << 1 << endl;
        return 0;
    }

    vector<int> dp(100005, 0);
    for ( int i = (a[0]==1?1:0); i < n; ++i )
    {
        int t = 1;
        for ( int j = 2; j*j <= a[i]; ++j )
        {
            if ( a[i]%j != 0 )
                continue;
            if ( dp[j] >= dp[t] )
                t = j;
            if ( dp[a[i]/j] >= dp[t] )
                t = a[i]/j;
        }
        dp[a[i]] = dp[t]+1;
        for ( int j = 2; j*j <= a[i]; ++j )
        {
            if ( a[i]%j != 0 )
                continue;
            dp[j] = max(dp[j], dp[a[i]]);
            dp[a[i]/j] = max(dp[a[i]/j], dp[a[i]]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
