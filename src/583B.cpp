#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &a[i]);
    int ans = 0, cnt = 0;
    while ( true )
    {
        for ( int i = 0; i < n; ++i )
        {
            while ( a[i] != -1 && cnt >= a[i] )
            {
                cnt += 1;
                a[i] = -1;
            }
        }
        if ( cnt < n )
            ans += 1;
        else
            break;
        for ( int i = n-1; i >= 0; --i )
        {
            while ( a[i] != -1 && cnt >= a[i] )
            {
                cnt += 1;
                a[i] = -1;
            }
        }
        if ( cnt < n )
            ans += 1;
        else
            break;
    }
    printf("%d\n", ans);
    return 0;
}
