#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int v, vector< vector<int> > &edges, vector<bool> &visited)
{
    if ( visited[v] )
        return;
    visited[v] = true;
    for ( unsigned int i = 0; i < edges[v].size(); ++i )
        dfs(edges[v][i], edges, visited);
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > edges(n);
    for ( int i = 0; i < m; ++i )
    {
        int x, y;
        cin >> x >> y;
        x -= 1, y -= 1;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    if ( n != m )
        cout << "NO" << endl;
    else
    {
        vector<bool> visited(n, false);
        dfs(0, edges, visited);
        if ( find(visited.begin(), visited.end(), false) == visited.end() )
            cout << "FHTAGN!" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
