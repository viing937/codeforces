#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int s = 0;
    unordered_map<int, vector<int>> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        s += a;
        m[a].push_back(i);
    }
    s = s / (n / 2);
    for (int i = 0; i < n/2; i++) {
        int c1 = m.begin()->first;
        int c2 = s-c1;
        cout << m[c1].back() << " ";
        if (m[c1].size() > 1)
            m[c1].pop_back();
        else
            m.erase(c1);
        cout << m[c2].back() << "\n";
        if (m[c2].size() > 1)
            m[c2].pop_back();
        else
            m.erase(c2);
    }
    return 0;
}
