#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int result = 0;
    for (int i = 1; i < n; i++) {
        int t = a[i];
        a[i] = max(a[i], k-a[i-1]);
        result += a[i] - t;
    }
    cout << result << "\n";
    for (int i = 0; i < n-1; i++)
        cout << a[i] << " ";
    cout << a[n-1] << "\n";
    return 0;
}
