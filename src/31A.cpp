#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mark;
    for ( int i = 0; i < n; ++i )
    {
        cin >> a[i];
        mark[a[i]] = i;
    }
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = i+1; j < n; ++j )
        {
            if ( mark.find(a[i]+a[j]) != mark.end() )
            {
                cout << mark[a[i]+a[j]]+1 << ' ' << i+1 << ' ' << j+1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
