#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int result = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        result += 1;
    }
    cout << result << endl;
    return 0;
}
