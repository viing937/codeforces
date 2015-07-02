#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    map<string, int> cnt;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        string s;
        cin >> s;
        cnt[s]++;
    }
    int ans = 0;
    for ( auto it = cnt.begin(); it != cnt.end(); it++ )
        if ( it->second > ans )
            ans = it->second;
    cout << ans << endl;
    return 0;
}
