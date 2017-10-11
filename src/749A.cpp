#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num2, num3;
    if (n%2) {
        num2 = (n-3)/2;
        num3 = 1;
    }
    else {
        num2 = n/2;
        num3 = 0;
    }
    string result;
    for (int i = 0; i < num2; i++) result += "2 ";
    for (int i = 0; i < num3; i++) result += "3 ";
    cout << num2+num3 << "\n";
    result.back() = '\n';
    cout << result;
    return 0;
}
