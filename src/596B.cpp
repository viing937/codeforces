#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 0, cur = 0;
    for ( int i = 0; i < n; ++i )
    {
        long long b;
        cin >> b;
        ans += abs(cur-b);
        cur = b;
    }
    cout << ans << endl;
    return 0;
}
