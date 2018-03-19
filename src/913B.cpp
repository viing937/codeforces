#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        m[p].push_back(i);
    }
    bool r = true;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second.size() == 0) continue;
        int cnt = 0;
        int parent = it->first;
        for (auto child: m[parent])
            if (m[child].size() == 0)
                cnt += 1;
        if (cnt < 3)
            r = false;
    }
    cout << (r ? "Yes" : "No") << endl;
    return 0;
}
