#include <iostream>
#include <cmath>
using namespace std;

long long s(long long x)
{
    long long s = 0;
    while ( x )
    {
        s += x%10;
        x /= 10;
    }
    return s;
}

int main()
{
    long long n;
    cin >> n;
    for ( long long b = 1; b <= 90; ++b )
    {
        double delte = b*b+4*n;
        if ( delte < 0 ) continue;
        long long x = (long long)((sqrt(delte)-b)/2+0.5);
        if ( s(x) == b && x*x+b*x-n == 0 )
        {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
