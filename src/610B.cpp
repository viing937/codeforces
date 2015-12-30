#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i];
    vector<int> s;
    int minval = *min_element(a.begin(), a.end()), t = 0;
    for ( int i = 0; i < n; ++i )
    {
        t += 1;
        if ( a[i] == minval )
        {
            s.push_back(t-1);
            t = 0;
        }
    }
    s[0] += t;
    cout << (long long)minval*n+(*max_element(s.begin(), s.end())) << endl;
    return 0;
}
