#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        m[t] += 1;
    }
    int r = 0;
    for (int i = 0; i < x; i++)
        if (m[i] == 0)
            r += 1;
    r += m[x];
    cout << r << endl;
    return 0;
}
