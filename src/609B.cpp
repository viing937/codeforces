#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m+1, 0);
    for ( int i = 0; i < n; ++i )
    {
        int a;
        cin >> a;
        cnt[a] += 1;
    }
    int ans = 0;
    for ( int i = 1; i <= m; ++i )
        for ( int j = i+1; j <= m; ++j )
            ans += cnt[i]*cnt[j];
    cout << ans << endl;
    return 0;
}
