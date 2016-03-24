#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int n, const vector<int> &par)
{
    return par[n] == n ? n : find(par[n], par);
}

void merge(int a, int b, vector<int> &par, vector<int> &size)
{
    int aa = find(a, par), bb = find(b, par);
    par[aa] = bb;
    size[bb] += size[aa];
}

int main()
{
    int n;
    cin >> n;

    vector< pair<int, int> > p(n);
    for ( int i = 0; i < n; ++i )
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end(), greater< pair<int, int> >());

    vector<int> par(n), size(n), mark(n);
    for ( int i = 0; i < n; ++i )
        par[i] = i, size[i] = 1;

    vector<int> ans;
    for ( int i = 0; i < n; ++i )
    {
        int pos = p[i].second, val = p[i].first;
        mark[pos] = 1;
        if ( pos > 0 && mark[pos-1] )
            merge(pos, pos-1, par, size);
        if ( pos < n-1 && mark[pos+1] )
            merge(pos, pos+1, par, size);
        int sz = size[find(pos, par)];
        while ( (int)ans.size() < sz )
            ans.push_back(val);
    }

    for ( int i = 0; i < n; ++i )
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
