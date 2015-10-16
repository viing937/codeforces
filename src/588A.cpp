#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n), p(n);
    for ( int i = 0; i < n; ++i )
        scanf("%d%d", &a[i], &p[i]);
    for ( int i = n-2; i >= 0; --i )
        a[i] += a[i+1];
    int result = a[0]*p[0], price = p[0];
    for ( int i = 1; i < n; ++i )
    {
        if ( p[i] < price )
        {
            result -= a[i]*(price-p[i]);
            price = p[i];
        }
    }
    printf("%d\n", result);
    return 0;
}
