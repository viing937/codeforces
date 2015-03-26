#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    int n, m;
    int a[100005];
    int ans[100005];
    cin >> n >> m;;
    for( int i=0; i<n; i++ )
        cin >> a[i];
    for( int i=n-1; i>=0; i-- )
    {
        s.insert(a[i]);
        ans[i] = s.size();
    }
    for( int i=0; i<m; i++ )
    {
        int tmp;
        cin >> tmp;
        cout << ans[tmp-1] << endl;
    }
    return 0;
}
