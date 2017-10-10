#include <iostream>
#include <vector>
using namespace std;

bool isVowel(char ch) {
    return ch == 'A' || ch == 'E' || ch == 'I' ||
           ch == 'O' || ch == 'U' || ch == 'Y';
}

int main() {
    string s;
    cin >> s;
    int cur = -1, result = INT_MIN;
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || isVowel(s[i])) {
            result = max(result, i-cur);
            cur = i;
        }
    }
    cout << result << endl;
    return 0;
}
