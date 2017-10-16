#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool result = false;
    for (int i = 0; i < n; i++) {
        string name;
        int before, after;
        cin >> name >> before >> after;
        result = result || (before >= 2400 && after > before);
    }
    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
