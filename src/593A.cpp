#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector< set<char> > a;
    vector<int> count;
    for ( int i = 0; i < n; ++i )
    {
        string s;
        cin >> s;
        count.push_back(s.size());
        a.push_back(set<char>());
        for ( auto ch : s )
            a.back().insert(ch);
    }
    int ans = 0;
    for ( char i = 'a'; i <= 'z'; ++i )
    {
        for ( char j = i+1; j <= 'z'; ++j )
        {
            int cnt = 0;
            for ( int k = 0; k < n; ++k )
            {
                if ( a[k].size() > 2 )
                    continue;
                if ( a[k].size() == 1 && a[k].find(i) == a[k].end() && a[k].find(j) == a[k].end() )
                    continue;
                if ( a[k].size() == 2 && (a[k].find(i) == a[k].end() || a[k].find(j) == a[k].end()) )
                    continue;
                cnt += count[k];
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
