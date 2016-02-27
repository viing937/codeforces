#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    for ( x = 0; x <= c/a; ++x )
    {
        y = (c-a*x)/b;
        if ( a*x+b*y == c )
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
