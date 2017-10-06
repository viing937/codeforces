#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string color;
    bool isColorful = false;
    for (int i = 0; i < n*m; i++) {
        cin >> color;
        isColorful = isColorful || color[0] == 'C' || color[0] == 'M' || color[0] == 'Y';
    }
    cout << (isColorful ? "#Color" : "#Black&White") << "\n";
    return 0;
}
