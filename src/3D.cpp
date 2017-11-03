#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    int b = 0;
    long long cost = 0;
    set<pair<int, int>> st;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            b += 1;
        else if (s[i] == ')')
            b -= 1;
        else {
            int l, r;
            cin >> l >> r;
            s[i] = ')';
            cost += r;
            b -= 1;
            st.emplace(l-r, i);
        }
        while (b < 0 && st.size()) {
            s[st.begin()->second] = '(';
            cost += st.begin()->first;
            b += 2;
            st.erase(st.begin());
        }
        if (b < 0) break;
    }
    if (b != 0)
        cout << "-1" << "\n";
    else
        cout << cost << "\n" << s << "\n";
    return 0;
}
