#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector< vector<int> > a(2, vector<int>(n, 0));

    for ( int i = 1; i < n; ++i )
        scanf("%d", &a[0][i]);
    for ( int i = 1; i < n; ++i )
        a[0][i] += a[0][i-1];

    for ( int i = 0; i < n-1; ++i )
        scanf("%d", &a[1][i]);
    for ( int i = n-2; i >= 0; --i )
        a[1][i] += a[1][i+1];

    vector<int> result;
    for ( int i = 0; i < n; ++i )
    {
        int t;
        scanf("%d", &t);
        result.push_back(a[0][i]+a[1][i]+t);
    }
    sort(result.begin(), result.end());
    printf("%d\n", result[0]+result[1]);
    return 0;
}
