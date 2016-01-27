#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i];
    int k = 0;
    while ( k < n && a[k] == 0 )
        k += 1;
    if ( k >= n )
    {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 1;
    for ( int i = k+1; i < n; ++i )
    {
        if ( a[i] == 0 )
            continue;
        else
        {
            ans *= (i-k);
            k = i;
        }
    }
    cout << ans << endl;
    return 0;
}
