#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &h[i]);
    vector<int> a(n, 0);
    for ( int i = n-2; i >= 0; --i )
    {
        a[i] = max(0, h[i+1]-h[i]+1);
        h[i] = max(h[i], h[i+1]);
    }
    for ( int i = 0; i < n-1; ++i )
        printf("%d ", a[i]);
    printf("%d\n", a[n-1]);
    return 0;
}
