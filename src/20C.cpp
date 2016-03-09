#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print_path(int k, const vector<int> &p)
{
    if ( p[k] != k )
        print_path(p[k], p);
    cout << k+1 << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector< pair<int, int> > > v(n, vector< pair<int, int> >());
    for ( int i = 0; i < m; ++i )
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a-1].push_back(make_pair(b-1, -w));
        v[b-1].push_back(make_pair(a-1, -w));
    }
    vector<int> g(n), p(n, -1);
    priority_queue< pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(0, 0)));
    while ( !q.empty() )
    {
        int a = q.top().first, k = q.top().second.first;
        if ( !g[k] )
        {
            g[k] = 1;
            p[k] = q.top().second.second;
            q.pop();
            for ( int i = 0; i < (int)v[k].size(); ++i )
                q.push(make_pair(a+v[k][i].second, make_pair(v[k][i].first, k)));
        }
        else
            q.pop();
    }
    if ( p[n-1] == -1 )
        cout << -1 << endl;
    else
    {
        print_path(n-1, p);
        cout << endl;
    }
    return 0;
}
