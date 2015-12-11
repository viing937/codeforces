#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cnt(n+1, 0);
    for ( int i = 0; i < n; ++i )
    {
        int t;
        cin >> t;
        cnt[t] = cnt[t-1]+1;
    }
    cout << n-*max_element(cnt.begin(), cnt.end()) << endl;
    return 0;
}
