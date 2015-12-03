#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for ( int i = 0; i < n; ++i )
        cin >> s[i];
    int a = min(2*k-n, n), b = max(n-k, 0);
    int ans = 0;
    for ( int i = 0; i < a; ++i )
        ans = max(ans, s[n-1-i]);
    for ( int i = 0; i < b; ++i )
        ans = max(ans, s[i]+s[n-1-a-i]);
    cout << ans << endl;
    return 0;
}
