#include <iostream>
using namespace std;

int helper(int n) {
    if (n == 0) return 1;
    int t = helper(n/2);
    return t * t * (n%2 ? 8 : 1) % 10;
}

int main() {
    int n;
    cin >> n;
    cout << helper(n) << endl;
    return 0;
}
