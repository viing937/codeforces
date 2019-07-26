#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long rls = 0;
    vector<long long> dp(1, 0);
    for (auto ai : a)
    {
        dp.push_back(0);
        rotate(dp.begin(), dp.begin() + dp.size() - 1, dp.end());
        for_each(dp.begin() + 1, dp.end(), [ai](long long &x) { x += ai; });
        dp[1] -= k;
        if (dp.size() > m)
        {
            dp[0] = max(dp[0], dp.back());
            dp.pop_back();
        }
        rls = max(rls, *max_element(dp.begin(), dp.end()));
    }
    cout << rls << endl;
    return 0;
}