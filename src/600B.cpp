#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> ans(m);
    for ( int i = 0; i < m; ++i )
    {
        int temp;
        cin >> temp;
        ans[i] = upper_bound(a.begin(), a.end(), temp, less<int>())-a.begin();
    }
    for ( int i = 0; i < m-1; ++i )
        cout << ans[i] << ' ';
    cout << ans.back() << '\n';
    return 0;
}
