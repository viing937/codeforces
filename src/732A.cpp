#include <iostream>
using namespace std;

int main() {
    int k, r;
    cin >> k >> r;
    int result = 1;
    while (result < 10) {
        int t = k * result % 10;
        if (t == 0 || t == r)
            break;
        result += 1;
    }
    cout << result << endl;
    return 0;
}
