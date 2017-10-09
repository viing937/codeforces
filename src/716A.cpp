#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    int result = 1;
    for (int i = 1; i < n; i++) {
        if (t[i] - t[i-1] <= c)
            result += 1;
        else
            result = 1;
    }
    cout << result << endl;
    return 0;
}
