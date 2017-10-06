#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> seats(n);
    for (int i = 0; i < n; i++)
        cin >> seats[i];
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (seats[i][0] == 'O' && seats[i][1] == 'O') {
            flag = true;
            seats[i][0] = seats[i][1] = '+';
            break;
        }
        if (seats[i][3] == 'O' && seats[i][4] == 'O') {
            flag = true;
            seats[i][3] = seats[i][4] = '+';
            break;
        }
    }
    if (!flag) {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n; i++)
        cout << seats[i] << "\n";
    return 0;
}
