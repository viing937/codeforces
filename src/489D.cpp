#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > e(n);
    vector< vector<int> > g(n, vector<int>(n));
    for ( int i = 0; i < m; ++i )
    {
        int a, b;
        cin >> a >> b;
        a -= 1, b -= 1;
        e[a].push_back(b);
        g[a][b] = 1;
    }

    int ans = 0;
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < n; ++j )
        {
            if ( i == j )
                continue;
            int cnt = 0;
            for ( int k = 0; k < (int)e[i].size(); ++k )
                if ( g[e[i][k]][j] )
                    cnt += 1;
            ans += cnt*(cnt-1)/2;
        }
    }
    cout << ans << endl;
    return 0;
}
