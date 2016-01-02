#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    for ( int i = 0; i < n; ++i )
    {
        int f;
        cin >> f;
        m[f] = i+1;
    }
    long long ans = 0;
    int cur = m.begin()->second;
    for ( auto it = m.begin(); it != m.end(); ++it )
    {
        ans += abs(cur-it->second);
        cur = it->second;
    }
    cout << ans << endl;
    return 0;
}
