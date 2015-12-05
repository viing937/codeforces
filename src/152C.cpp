#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MOD (1000*1000*1000+7)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> names(n);
    for ( int i = 0; i < n; ++i )
        cin >> names[i];
    long long ans = 1;
    for ( int i = 0; i < m; ++i )
    {
        set<char> cnt;
        for ( int j = 0; j < n; ++j )
            cnt.insert(names[j][i]);
        ans = (ans*cnt.size())%MOD;
    }
    cout << ans << endl;
    return 0;
}
