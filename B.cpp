#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector< set<int> > graph(n+1, set<int>());
    for ( int i = 0; i < m; ++i )
    {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    int result = 0x7fffffff;
    for ( int i = 1; i <= n; ++i  )
    {
        for ( auto a = graph[i].begin(); a != graph[i].end(); ++a )
            for ( auto b = next(a, 1); b != graph[i].end(); ++b )
                if ( graph[*a].find(*b) != graph[*a].end() )
                    result = min(result, (int)(graph[i].size()+graph[*a].size()+graph[*b].size()-6));
    }
    if ( result != 0x7fffffff )
        cout << result << endl;
    else
        cout << -1 << endl;
    return 0;
}
