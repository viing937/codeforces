#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') continue;
        int j = i+1;
        while (j < n && s[j] == 'B')
            j += 1;
        result.push_back(j-i);
        i = j;
    }
    cout << result.size() << "\n";
    if (result.size()) {
        for (int i = 0; i < result.size()-1; i++)
            cout << result[i] << " ";
        cout << result.back() << "\n";
    }
    return 0;
}
