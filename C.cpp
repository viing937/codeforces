#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, t;
    cin >> a;
    while ( a%2 == 0 )
        a /= 2;
    while ( a%3 == 0 )
        a /= 3;
    t = a;
    for ( int i = 1; i < n; ++i )
    {
        cin >> a;
        while ( a%2 == 0 )
            a /= 2;
        while ( a%3 == 0 )
            a /= 3;
        if ( t != a )
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
