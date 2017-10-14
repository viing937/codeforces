#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x.begin(), x.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        cout << upper_bound(x.begin(), x.end(), m) - x.begin() << "\n";
    }
    return 0;
}
