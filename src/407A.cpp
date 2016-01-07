#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    while ( b )
    {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    vector<int> x, y, z;
    for ( int i = 3; i < 1000; ++i )
    {
        for ( int j = i; j < 1000; ++j )
        {
            int k = sqrt(i*i+j*j);
            if ( i*i + j*j == k*k && gcd(i, j) == 1 && gcd(i, k) == 1 && gcd(j, k) == 1 && k <= 1000 )
            {
                x.push_back(i);
                y.push_back(j);
                z.push_back(k);
            }
        }
    }

    int a, b;
    cin >> a >> b;
    for ( int i = 0; i < (int)x.size(); ++i )
    {
        if ( a%z[i] == 0 && b%z[i] == 0 )
        {
            cout << "YES" << '\n';
            int k1 = a/z[i], k2 = b/z[i];
            if ( y[i]*k1 != x[i]*k2 )
            {
                cout << 0 << ' ' << 0 << '\n';
                cout << -x[i]*k1 << ' ' << y[i]*k1 << '\n';
                cout << y[i]*k2 << ' ' << x[i]*k2 << '\n';
            }
            else
            {
                cout << 0 << ' ' << 0 << '\n';
                cout << y[i]*k1 << ' ' << x[i]*k1 << '\n';
                cout << -x[i]*k2 << ' ' << y[i]*k2 << '\n';
            }
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}
