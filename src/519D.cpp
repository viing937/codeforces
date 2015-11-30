#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<int> x(26);
    for ( int i = 0; i < 26; ++i )
        cin >> x[i];

    string s;
    cin >> s;

    int len = s.size();

    vector<long long> sum(len);
    sum[0] = x[s[0]-'a'];
    for ( int i = 1; i < len; ++i )
        sum[i] = sum[i-1]+x[s[i]-'a'];

    vector< vector<int> > pos(26);
    for ( int i = 0; i < len; ++i )
        pos[s[i]-'a'].push_back(i);

    long long ans = 0;
    for ( int i = 0; i < 26; ++i )
    {
        map<long long, int> m;
        for ( int j = 0; j < (int)pos[i].size(); ++j )
        {
            int p = pos[i][j];
            ans += m[p>0?sum[p-1]:0];
            m[sum[p]] += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
