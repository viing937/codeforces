#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, w, h;
    cin >> n >> w >> h;
    
    vector< pair<int, pair<int, int> > > e(n);
    for ( int i = 0; i < n; ++i )
    {
        cin >> e[i].first >> e[i].second.first;
        e[i].second.second = i+1;
    }
    sort(e.begin(), e.end());

    vector<int> dp(n);
    for ( int i = 0; i < n; ++i )
        if ( e[i].first > w && e[i].second.first > h )
            dp[i] = 1;

    vector<int> g(n, -1);
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = i+1; j < n; ++j )
        {
            if ( e[j].first > w && e[j].second.first > h &&
                 e[j].first > e[i].first && e[j].second.first > e[i].second.first && dp[j] <= dp[i] )
            {
                dp[j] = dp[i]+1;
                g[j] = i;
            }
        }
    }

    int t = max_element(dp.begin(), dp.end()) - dp.begin(), idx = dp[t];
    vector<int> ans(idx);
    while ( (idx--) > 0 )
    {
        ans[idx] = e[t].second.second;
        t = g[t];
    }

    cout << ans.size() << '\n';
    for ( int i = 0; i < (int)ans.size(); ++i )
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
