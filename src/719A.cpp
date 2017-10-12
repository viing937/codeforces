#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a[n-1] == 0)
        cout << "UP" << "\n";
    else if (a[n-1] == 15)
        cout << "DOWN" << "\n";
    else if (n == 1)
        cout << "-1" << "\n";
    else if (a[n-1] > a[n-2])
        cout << "UP" << "\n";
    else
        cout << "DOWN" << "\n";
    return 0;
}
