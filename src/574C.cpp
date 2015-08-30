#include <iostream>
using namespace std;

int cal(int a)
{
    while ( a%2 == 0 )
        a /= 2;
    while ( a%3 == 0 )
        a /= 3;
    return a;
}

int main()
{
    int n;
    cin >> n;
    int a, t;
    cin >> a;
    t = cal(a);
    for ( int i = 1; i < n; ++i )
    {
        cin >> a;
        if ( t != cal(a) )
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
