#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char cur = 'a';
    int result = 0;
    for (auto ch: s) {
        int t = (cur + 26 - ch) % 26;
        result += min(t, 26-t);
        cur = ch;
    }
    cout << result << endl;
    return 0;
}
