#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i];
    vector<bool> used(n+1, false);
    for ( int i = 0; i < n; ++i )
        if ( a[i] <= n )
            used[a[i]] = true;
    set<int> notused;
    for ( int i = 1; i <= n; ++i )
        if ( !used[i] )
            notused.insert(i);
    fill(used.begin(), used.end(), false);
    for ( int i = 0; i < n; ++i )
    {
        if ( a[i] > n || used[a[i]] )
        {
            a[i] = *notused.begin();
            notused.erase(notused.begin());
        }
        used[a[i]] = true;
    }
    cout << a[0];
    for ( int i = 1; i < n; ++i )
        cout << ' ' << a[i];
    cout << endl;
    return 0;
}
