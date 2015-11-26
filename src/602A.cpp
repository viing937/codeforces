#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int bx, by;
    long long x = 0, y = 0;
    int digit;
    cin >> n >> bx;
    for ( int i = 0; i < n; ++i )
    {
        cin >> digit;
        x = x*bx+digit;
    }
    cin >> m >> by;
    for ( int i = 0; i < m; ++i )
    {
        cin >> digit;
        y = y*by+digit;
    }
    if ( x == y )
        cout << '=' << endl;
    else if ( x < y )
        cout << '<' << endl;
    else if ( x > y )
        cout << '>' << endl;
    return 0;
}
