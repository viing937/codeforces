#include <iostream>
using namespace std;

int main()
{
    int n, active, diff;
    cin >> n >> active;
    diff = active;
    for ( int i = 1; i < n; i++ )
    {
        cin >> active;
        if ( i%2 )
            active = (active+n+diff)%n;
        else
            active = (active+n-diff)%n;
        if ( active != i )
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
