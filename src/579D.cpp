#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    vector<int> a(n), prefix(n, 0), suffix(n, 0);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &a[i]);

    prefix[0] = a[0];
    for ( int i = 1; i < n; ++i )
        prefix[i] = a[i] | prefix[i-1];

    suffix[n-1] = a[n-1];
    for ( int i = n-2; i >= 0; --i )
        suffix[i] = a[i] | suffix[i+1];

    for ( int i = 1, t = x; i < k; ++i )
        x *= t;

    long long result = 0;
    for ( int i = 0; i < n; ++i )
    {
        long long temp = (long long)x * a[i];
        if ( i-1 >= 0 )
            temp |= prefix[i-1];
        if ( i+1 < n )
            temp |= suffix[i+1];
        result = max(result, temp);
    }
    cout << result << '\n';
    return 0;
}
