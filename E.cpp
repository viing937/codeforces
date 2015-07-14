#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    int cnt = 0;
    int l[50005], r[50005], k[50005];
    char s[100005];
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    while ( q-- )
    {
        int ll, rr, kk;
        scanf("%d%d%d", &ll, &rr, &kk);
        if ( cnt <= 0 || kk != k[cnt-1] || ll <= r[cnt-1] || rr >= l[cnt-1] )
        {
            l[cnt] = ll, r[cnt] = rr, k[cnt] = kk;
            cnt++;
        }
        else if ( rr-ll > r[cnt-1]-l[cnt-1] )
            l[cnt-1] = ll, r[cnt-1] = rr;
    }
    for ( int i = 0; i < cnt; i++ )
    {
        if ( k[i] == 1 )
            sort(s+l[i]-1, s+r[i], less<char>());
        else
            sort(s+l[i]-1, s+r[i], greater<char>());
    }
    printf("%s\n", s);
    return 0;
}
