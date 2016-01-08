#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> r(2*n+1);
    for ( int i = 0; i < 2*n+1; ++i )
        cin >> r [i];
    for ( int i = 0; i < n && k; ++i )
    {
        int peak = 2*i+1;
        if ( r[peak]-1 > r[peak-1] && r[peak]-1 > r[peak+1] )
        {
            r[peak] -= 1;
            k -= 1;
        }
    }
    for ( int i = 0; i < 2*n; ++i )
        cout << r[i] << ' ';
    cout << r.back() << '\n';
    return 0;
}
