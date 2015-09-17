#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n+1), dp(n+1);
    for ( int i = 1; i <= n; ++i )
        cin >> h[i];
    for ( int i = 1, worst = 0; i <= n; ++i )
    {
        worst = min(worst, h[i]-i);
        dp[i] = i + worst;
    }
    for ( int i = n, worst = n+1; i >= 1; --i )
    {
        worst = min(worst, h[i]+i);
        dp[i] = min(dp[i], worst-i);
    }
    cout << *max_element(dp.begin()+1, dp.end()) << endl;
    return 0;
}
