#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, k, a;
    cin >> n >> k;
    map<int, long long> dp, cnt;
    long long ans = 0;
    for ( int i = 0; i < n; ++i )
    {
        cin >> a;
        if ( a%k == 0 )
        {
            ans += dp[a/k];
            dp[a] += cnt[a/k];
        }
        cnt[a] += 1;
    }
    cout << ans << endl;
    return 0;
}
