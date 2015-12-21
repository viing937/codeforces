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
    sort(a.begin(), a.end(), greater<int>());
    int s = a[0], cnt = 1;
    while ( m > s )
        s += a[cnt++];
    cout << cnt << endl;
    return 0;
}
