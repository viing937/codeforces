#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector< pair<int, int> > castles;
    for ( int i = 1; i <= n; ++i )
    {
        int h;
        cin >> h;
        castles.push_back(make_pair(h, i));
    }
    sort(castles.begin(), castles.end());
    int ans = 0;
    for ( int i = 0; i < n; )
    {
        ans += 1;
        int last = castles[i].second;
        while ( i < last )
        {
            last = max(last, castles[i].second);
            i += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
