#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> cnt;
    for ( int i = 0; i < n; ++i )
    {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    int ans = a[0];
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = i; j < n; ++j )
        {
            int segsum = 0;
            map<int, int> segmentcnt, tmpcnt(cnt);
            for ( int k = i; k <= j; ++k )
            {
                segsum += a[k];
                segmentcnt[a[k]] += 1;
                tmpcnt[a[k]] -= 1;
                if ( tmpcnt[a[k]] == 0 )
                    tmpcnt.erase(a[k]);
            }
            for ( int k = 0; k < m; ++k )
            {
                auto inIt = segmentcnt.begin();
                auto outIt = tmpcnt.rbegin();
                if ( inIt == segmentcnt.end() || outIt == tmpcnt.rend() )
                        break;
                int in = inIt->first, out = outIt->first;
                if ( in >= out )
                    break;
                segsum = segsum - in + out;
                segmentcnt[out] += 1;
                segmentcnt[in] -= 1;
                tmpcnt[out] -= 1;
                tmpcnt[in] += 1;
                if ( segmentcnt[in] == 0 ) segmentcnt.erase(in);
                if ( tmpcnt[out] == 0 ) tmpcnt.erase(out);
            }
            ans = max(ans, segsum);
        }
    }
    cout << ans << endl;
    return 0;
}
