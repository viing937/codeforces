#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

long long cnt(long long a, long long b)
{
    if ( a%b )
        return a/b+1;
    else
        return a/b;
}

long long cal(int k, long long a, long long b, long long base[])
{
    return cnt(base[k], a)-(cnt((b+1)*base[k-1], a)-cnt(b*base[k-1], a));
}

int main()
{
    long long base[10] = {1};
    for ( int i = 1; i < 10; ++i )
        base[i] = base[i-1]*10;
    int n, k;
    cin >> n >> k;
    vector<long long> a(n/k), b(n/k);
    for ( int i = 0; i < n/k; ++i )
        cin >> a[i];
    for ( int i = 0; i < n/k; ++i )
        cin >> b[i];
    long long ans = 1;
    for ( int i = 0; i < n/k; ++i )
        ans = ans*cal(k, a[i], b[i], base)%MOD;
    cout << ans << endl;
    return 0;
}
