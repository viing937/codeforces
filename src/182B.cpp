#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int d, n;
    cin >> d >> n;
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i];
    int ans = 0;
    for ( int i = 1; i < n; ++i )
        ans += d-a[i-1];
    cout << ans << endl;
    return 0;
}
