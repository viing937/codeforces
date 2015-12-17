#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if ( k > (n-1)/2 ) {cout << -1 << endl; return 0;}
    cout << n*k << '\n';
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= k; ++j )
            cout << i << ' ' << (i+j-1)%n+1 << '\n';
    return 0;
}
