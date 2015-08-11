#include <iostream>
using namespace std;

int main()
{
    int t, s, q;
    cin >> t >> s >> q;
    int ans = 0;
    while ( s < t  )
    {
        ans += 1;
        s *= q;
    }
    cout << ans << endl;
    return 0;
}
