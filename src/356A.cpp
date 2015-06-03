#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> alive;
    for ( int i = 1; i <= n; i++ )
        alive.insert(i);
    vector<int> f(n+1, 0);
    while ( m-- )
    {
        int l, r, x;
        cin >> l >> r >> x;
        for ( set<int>::iterator it = alive.lower_bound(l); it != alive.end(); it++ )
        {
            if ( *it > r )
                break;
            if ( *it != x )
                f[*it] = x;
        }
        alive.erase(alive.lower_bound(l), alive.upper_bound(r));
        alive.insert(x);
    }
    cout << f[1];
    for ( int i = 2; i <= n; i++ )
        cout << " " << f[i];
    cout << "\n";
    return 0;
}
