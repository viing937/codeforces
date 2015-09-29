#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int &a, const int &b)
{
    return (a%10) < (b%10);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &a[i]);
    sort(a.begin(), a.end(), cmp);
    int result = 0, cnt = 0;
    for ( int i = n-1; i >= 0; --i )
    {
        int p = a[i]/10, q = a[i]%10;
        if ( k >= 10-q )
        {
            result += p+1;
            cnt += 9-p;
            k -= 10-q;
        }
        else
        {
            result += p;
            cnt += 10-p;
        }
    }
    printf("%d\n", result+min(k/10, cnt));
    return 0;
}
