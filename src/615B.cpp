#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > edge(n);
    vector<int> degree(n, 0);
    for ( int i = 0; i < m; ++i )
    {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        if ( u > v )
            swap(u, v);
        edge[u].push_back(v);
        degree[u] += 1, degree[v] += 1;
    }

    vector<int> dp(n, 1);
    long long ans = 0;
    for ( int i = 0; i < n; ++i )
    {
        for ( int p : edge[i] )
            dp[p] = max(dp[i]+1, dp[p]);
        ans = max(ans, (long long)dp[i]*degree[i]);
    }
    cout << ans << endl;
    return 0;
}
