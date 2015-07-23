#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[6];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
    int ans = (a[0]+a[1])*(a[2]+a[3])*2-a[0]*a[0]-a[3]*a[3];
    cout << ans << endl;
    return 0;
}
