#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> f(n), a(m), b(m);
    map<int, int> fcnt, inv;
    for ( int i = 0; i < n; ++i )
    {
        cin >> f[i];
        fcnt[f[i]] += 1;
        inv[f[i]] = i+1;
    }
    for ( int i = 0; i < m; ++i )
        cin >> b[i];
    for ( int i = 0; i < m; ++i )
    {
        if ( fcnt.find(b[i]) == fcnt.end() )
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for ( int i = 0; i < m; ++i )
    {
        if ( fcnt[b[i]] > 1 )
        {
            cout << "Ambiguity" << endl;
            return 0;
        }
    }
    for ( int i = 0; i < m; ++i )
        a[i] = inv[b[i]];
    cout << "Possible" << '\n';
    for ( int i = 0; i < m-1; ++i )
        cout << a[i] << ' ';
    cout << a[m-1] << '\n';
    return 0;
}
