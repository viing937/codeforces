#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int mi, ci;
        cin >> mi >> ci;
        m += mi > ci ? 1 : 0;
        c += mi < ci ? 1 : 0;
    }
    if (m > c)
        cout << "Mishka" << "\n";
    else if (m < c)
        cout << "Chris" << "\n";
    else
        cout << "Friendship is magic!^^" << "\n";
    return 0;
}
