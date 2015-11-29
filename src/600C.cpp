#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for ( auto ch : s )
        cnt[ch-'a'] += 1;
    for ( int i = 0; i < 26; ++i )
    {
        if ( cnt[i]%2 == 0 )
            continue;
        for ( int j = 25; j >= i; --j )
        {
            if ( cnt[j]%2 )
            {
                cnt[i] += 1;
                cnt[j] -= 1;
                break;
            }
        }
    }
    string ans(s);
    if ( s.size()%2 )
    {
        int k;
        for ( k = 0; k < 26; ++k )
            if ( cnt[k]%2 )
                break;
        ans[s.size()/2] = k+'a';
        cnt[k] -= 1;
    }
    int index = 0;
    for ( int i = 0; i < 26; ++i )
    {
        for ( int j = 0; j < cnt[i]/2; ++j )
        {
            ans[index] = i+'a';
            ans[s.size()-1-index] = i+'a';
            index += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
