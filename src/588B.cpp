#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long result = 1;
    for ( long long factor = 2; factor <= sqrt(n); ++factor )
    {
        if ( n%factor != 0 )
            continue;
        while ( n%factor == 0 )
            n /= factor;
        result *= factor;
    }
    cout << result*n << endl;
    return 0;
}
