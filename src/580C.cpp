#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void dfs(int root, int count, int m, int &result, vector< vector<int> > &graph, vector<int> &hascat, vector<int> &visited)
{
    visited[root] = 1;
    if ( hascat[root] )
        count += 1;
    else
        count = 0;
    if ( count > m )
        return;
    if ( root != 1 && graph[root].size() == 1 )
    {
        result += 1;
        return;
    }
    for ( unsigned int i = 0; i < graph[root].size(); ++i )
    {
        if ( !visited[graph[root][i]] )
            dfs(graph[root][i], count, m, result, graph, hascat, visited);
    }
    return;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> hascat(n+1);
    for ( int i = 1; i <= n; ++i )
        scanf("%d", &hascat[i]);
    vector< vector<int> > graph(n+1, vector<int>());
    for ( int i = 0; i < n-1; ++i )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> visited(n+1, 0);
    int result = 0;
    dfs(1, 0, m, result, graph, hascat, visited);
    printf("%d\n", result);
    return 0;
}
