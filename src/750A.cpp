#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    k = (240 - k) / 5;
    int result = sqrt(k*2);
    if ((1+result)*result/2 > k) result -= 1;
    cout << min(n, result) << endl;
    return 0;
}
