#include <iostream>
#include <vector>
using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i'
        || ch == 'o' || ch == 'u' || ch == 'y';
}

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (!isVowel(s[i]))
            s[idx++] = s[i];
        else if (idx == 0 || !isVowel(s[idx-1]))
            s[idx++] = s[i];
    }
    s.resize(idx);
    cout << s << endl;
    return 0;
}
