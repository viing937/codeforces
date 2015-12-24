#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    long long q;
    cin >> q;
    vector<long long> factor;
    for ( long long i = 2, p = q; i <= sqrt(p); ++i )
    {
        while ( p%i == 0 )
        {
            p /= i;
            factor.push_back(i);
        }
    }
    if ( factor.size() < 1 )
        cout << 1 << '\n' << 0 << endl;
    else if ( factor.size() == 1 || factor[0]*factor[1] == q )
        cout << 2 << endl;
    else
        cout << 1 << '\n' << factor[0]*factor[1] << endl;
    return 0;
}
