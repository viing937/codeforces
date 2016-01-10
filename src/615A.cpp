#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> status(m+1, false);
    for ( int i = 0; i < n; ++i )
    {
        int x, y;
        cin >> x;
        while ( x-- )
        {
            cin >> y;
            status[y] = true;
        }
    }
    for ( int i = 1; i <= m; ++i )
    {
        if ( !status[i] )
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
