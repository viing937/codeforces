#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> s(n);
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            map<char, int> ct = {{'R', 0}, {'G', 1}, {'B', 2}};
            s[i] = ct[c];
        }

        vector<vector<int>> dp(3, vector<int>(n + 1));
        dp[0][1] = dp[1][1] = dp[2][1] = 1;
        dp[s[0]][1] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int cur = 0; cur < 3; cur++)
            {
                int prev = (cur + 2) % 3;
                if (s[i] == cur)
                    dp[cur][i + 1] = dp[prev][i];
                else
                    dp[cur][i + 1] = dp[prev][i] + 1;
            }
        }
        int rls = 0x7FFFFFFF;
        for (int i = k; i <= n; i++)
        {
            for (int cur = 0; cur < 3; cur++)
            {
                int prev = ((cur - k) % 3 + 3) % 3;
                rls = min(rls, dp[cur][i] - dp[prev][i - k]);
            }
        }
        cout << rls << endl;
    }
    return 0;
}