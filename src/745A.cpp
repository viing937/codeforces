#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    set<string> dict;
    for (int i = 0; i < n; i++) {
        dict.insert(s);
        rotate(s.begin(), s.begin()+1, s.end());
    }
    cout << dict.size() << endl;
    return 0;
}
