#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > c(n, vector<int>(m));
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            cin >> c[i][j];
    int ans = *min_element(c[0].begin(), c[0].end());
    for ( int i = 1; i < n; ++i )
        ans = max(ans, *min_element(c[i].begin(), c[i].end()));
    cout << ans << endl;
    return 0;
}
