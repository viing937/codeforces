#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    if ( t == 10 )
    {
        if ( n == 1 )
            cout << -1 << '\n';
        else
        {
            cout << 1;
            for ( int i = 0; i < n-1; ++i )
                cout << 0;
            cout << '\n';
        }
    }
    else
    {
        for ( int i = 0; i < n; ++i )
            cout << t;
        cout << '\n';
    }
    return 0;
}
