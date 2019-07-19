#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> count(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        count[t] += 1;
    }
    auto lambda = [](int a, int b) { return a + b % 2; };
    int remainder = accumulate(count.begin(), count.end(), 0, lambda);
    cout << n - (remainder / 2) << endl;
    return 0;
}