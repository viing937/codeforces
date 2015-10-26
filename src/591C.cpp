#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int update(vector<int> &a, int left, int right)
{
    if ( left > right )
        return 0;
    int cnt;
    for ( cnt = 0; left+cnt <= right-cnt; ++cnt )
    {
        a[left+cnt] = a[left-1];
        a[right-cnt] = a[right+1];
    }
    return cnt;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n+2);
    for ( int i = 1; i <= n; ++i )
        scanf("%d", &a[i]);
    a[0] = a[1], a[n+1] = a[n];
    int start = 1, result = 0;
    for ( int i = 2; i <= n+1; ++i )
    {
        if ( a[i] != a[i-1] )
            continue;
        result = max(result, update(a, start+1, i-2));
        start = i;
    }
    printf("%d\n", result);
    for ( int i = 1; i < n; ++i )
        printf("%d ", a[i]);
    printf("%d\n", a[n]);
    return 0;
}
