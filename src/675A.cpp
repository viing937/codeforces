#include <iostream>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if ( c == 0 )
    {
        if ( a == b )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        long long t = b-a;
        if ( t%c == 0 && t/c >= 0 )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
