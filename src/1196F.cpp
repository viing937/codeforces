#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<int, long long> dijkstra(int start, map<int, map<int, long long>> &g)
{
    map<int, long long> dismap;
    map<int, bool> visited;
    set<pair<long long, int>> pq;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        auto top = *pq.begin();
        pq.erase(top);
        auto &[d, cur] = top;
        if (visited[cur])
            continue;
        visited[cur] = true;
        for (auto &[v, w] : g[cur])
        {
            if (visited[v])
                continue;
            if (dismap.find(v) == dismap.end() || d + w < dismap[v])
            {
                dismap[v] = d + w;
                pq.emplace(dismap[v], v);
            }
        }
    }
    return dismap;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.emplace_back(w, x, y);
    }
    sort(edges.begin(), edges.end());

    map<int, map<int, long long>> g;
    for (int i = 0; i < min(k, m); i++)
    {
        auto &[w, x, y] = edges[i];
        g[x][y] = g[y][x] = w;
    }

    vector<long long> dis;
    for (auto it = g.begin(); it != g.end(); ++it)
    {
        int start = it->first;
        auto dismap = dijkstra(start, g);
        for_each(dismap.begin(), dismap.end(), [&dis](auto it) { dis.push_back(it.second); });
    }

    sort(dis.begin(), dis.end());
    long long rls = dis[k * 2 - 1];
    cout << rls << endl;
    return 0;
}