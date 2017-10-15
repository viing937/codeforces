#include <iostream>
using namespace std;

int factorial(int x) {
    return x == 0 ? 1 : x * factorial(x-1);
}

int main() {
    int A, B;
    cin >> A >> B;
    cout << factorial(min(A, B)) << "\n";
    return 0;
}
