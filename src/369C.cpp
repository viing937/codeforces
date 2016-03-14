#include <iostream>
#include <vector>
using namespace std;

void cal(int cur, int pre, const vector< vector<int> > &e, const vector<bool> &a, vector<int> &d)
{
    d[cur] = a[cur] ? 1 : 0;
    for ( int i = 0; i < (int)e[cur].size(); ++i )
    {
        if ( pre != e[cur][i] )
        {
            cal(e[cur][i], cur, e, a, d);
            d[cur] += d[e[cur][i]];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > e(n);
    vector<bool> a(n, false);
    for ( int i = 1; i < n; ++i )
    {
        int x, y, t;
        cin >> x >> y >> t;
        x -= 1, y -=1;
        e[x].push_back(y);
        e[y].push_back(x);
        if ( t == 2 )
            a[x] = a[y] = true;
    }
    vector<int> d(n);
    cal(0, 0, e, a, d);

    vector<int> ans;
    for ( int i = 0; i < n; ++i )
        if ( d[i] == 1 )
            ans.push_back(i+1);

    cout << ans.size() << '\n';
    for ( int i = 0; i < (int)ans.size(); ++i )
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
