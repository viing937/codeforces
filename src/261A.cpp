#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m;
    scanf("%d", &m);
    vector<int> q(m);
    for ( int i = 0; i < m; ++i )
        scanf("%d", &q[i]);
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &a[i]);
    sort(q.begin(), q.end());
    sort(a.begin(), a.end(), greater<int>());
    int result = 0, cnt = 0;
    for ( int i = 0; i < n; ++i )
    {
        result += a[i];
        cnt += 1;
        if ( cnt == q[0] )
        {
            cnt = 0;
            i += 2;
        }
    }
    printf("%d\n", result);
    return 0;
}
