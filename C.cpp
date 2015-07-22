#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[6];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
    if ( a[0] == a[3] && a[1] == a[4] && a[2] == a[5] )
    {
        sort(a, a+3);
        int minlen = a[0];
        int ans = 0;
        ans += 2*((a[0]-minlen+1+a[0])*minlen/2);
        ans += 2*((a[0]-minlen+a[0]-1)*minlen/2);
        ans += 2*((a[1]-minlen+1+a[1])*minlen/2);
        ans += 2*((a[1]-minlen+a[1]-1)*minlen/2);
        ans += 2*((a[2]-minlen+1+a[2])*minlen/2);
        ans += 2*((a[2]-minlen+a[2]-1)*minlen/2);
        ans += (a[1]-minlen)*(a[2]-minlen)*2;
        cout << ans << endl;
    }
    else
    {
        int ans = 0;
        int minlen = min(a[0], a[3]);
        ans += 3*((a[0]-minlen+1+a[0])*minlen/2);
        ans += 3*((a[0]-minlen+a[0]-1)*minlen/2);
        ans += 3*((a[3]-minlen+1+a[3])*minlen/2);
        ans += 3*((a[3]-minlen+a[3]-1)*minlen/2);
        ans += max(a[0]-minlen, a[3]-minlen)*max(a[0]-minlen, a[3]-minlen);
        cout << ans << endl;
    }
    return 0;
}
