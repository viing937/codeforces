#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1)
        cout << 3 << endl;
    else if (n == 2)
        cout << 4 << endl;
    else if (n % 2)
        cout << 1 << endl;
    else
        cout << n-2 << endl;
    return 0;
}
