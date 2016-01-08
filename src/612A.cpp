#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, p, q;
    string s;
    cin >> n >> p >> q >> s;
    for ( int i = 0; i <= n; i += p )
    {
        for ( int j = 0; i+j <= n; j += q )
        {
            if ( i+j == n )
            {
                cout << i/p+j/q << '\n';
                for ( int k = 0; k < i; ++k )
                {
                    cout << s[k];
                    if ( (k+1)%p == 0 ) cout << '\n';
                }
                for ( int k = 0; k < j; ++k )
                {
                    cout << s[i+k];
                    if ( (k+1)%q == 0 ) cout << '\n';
                }
                return 0;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
