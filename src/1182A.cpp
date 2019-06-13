#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= 2)
            dp[i] += 2 * dp[i-2];
    }

    cout << dp[n] << endl;
    return 0;
}