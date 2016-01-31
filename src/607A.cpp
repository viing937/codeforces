#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
    vector<int> dp(1000005);

    vector< pair<int, int> > beacons;
    for ( int i = 0; i < n; ++i )
    {
        cin >> a >> b;
        beacons.push_back(make_pair(a, b));
    }
    sort(beacons.begin(), beacons.end());
    
    int cur = 0;
    for ( int i = 0; i < n; ++i )
    {
        a = beacons[i].first, b = beacons[i].second;
        while ( cur < a )
        {
            dp[cur+1] = dp[cur];
            cur += 1;
        }
        dp[a] = (a-b-1>=0) ? dp[a-b-1]+1 : 1;
    }

    cout << n-*max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
