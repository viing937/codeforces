#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > e(n+1, vector<int>(n+1, 0));
    for ( int i = 0; i < m; ++i )
    {
        int a, b;
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }
    vector<int> cnt(n+1, 0);
    for ( int i = 1; i <= n; ++i )
        cnt[i] = count(e[i].begin(), e[i].end(), 1);
    int result = 0;
    while ( count(cnt.begin(), cnt.end(), 1) > 0 )
    {
        result += 1;
        for ( int i = 1; i <= n; ++i )
        {
            if ( cnt[i] != 1 )
                continue;
            for ( int j = 1; j <= n; ++j )
            {
                e[j][i] = 0;
                e[i][j] = 0;
            }
        }
        for ( int i = 1; i <= n; ++i )
            cnt[i] = count(e[i].begin(), e[i].end(), 1);
    }
    cout << result << endl;
    return 0;
}
