#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    int u, v;
    cin >> n >> m;
    vector< vector<bool> > g(n, vector<bool>(n, false));
    vector<int> d(n, 0);
    for ( int i = 0; i < m; ++i )
    {
        cin >> u >> v;
        g[u-1][v-1] = g[v-1][u-1] = true;
    }
    queue<int> q;
    q.push(0);
    while ( !q.empty() )
    {
        v = q.front();
        q.pop();
        for ( u = 1; u < n; ++u )
        {
            if ( g[v][u] != g[0][n-1] && !d[u] )
            {
                d[u] = d[v]+1;
                q.push(u);
            }
        }
    }
    cout << (d[n-1]?d[n-1]:-1) << endl;
    return 0;
}
