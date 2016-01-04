#include <iostream>
using namespace std;

#define MOD 1000000007

long long quickpow(long long n)
{
    if ( n == 0 )
        return 1;
    long long part = quickpow(n/2);
    if ( n%2 )
        return part*part*2%MOD;
    else
        return part*part%MOD;
}

int main()
{
    long long n;
    cin >> n;
    if ( n == 0 )
    {
        cout << 1 << endl;
        return 0;
    }
    long long pro = quickpow(n-1);
    cout << (pro*2+1)*pro%MOD << endl;
    return 0;
}
