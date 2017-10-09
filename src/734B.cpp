#include <iostream>
using namespace std;

int main() {
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int num32, num256;
    num256 = min(k2, min(k5, k6));
    num32 = min(k2-num256, k3);
    int result = 256 * num256 + 32 * num32;
    cout << result << endl;
    return 0;
}
