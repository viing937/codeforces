#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; i++)
        diff[i] = a[i] - a[i + 1];

    sort(diff.begin(), diff.end());

    int rls = a[n - 1] - a[0] + accumulate(diff.begin(), diff.begin() + k - 1, 0);
    cout << rls << endl;
    return 0;
}