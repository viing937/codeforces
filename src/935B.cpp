#include <iostream>
using namespace std;

int main() {
    int n;
    string move;
    cin >> n;
    cin >> move;

    int x = 0, y = 0, r = 0, side = -1;
    for (int i = 0; i < n; i++) {
        if (move[i] == 'U')
            y += 1;
        else if (move[i] == 'R')
            x += 1;
        if (x+1 == y && side != 0)
            r += 1;
        if (x == y+1 && side != 1)
            r += 1;
        if (x < y) side = 0;
        if (x > y) side = 1;
    }
    cout << r - 1 << endl;
    return 0;
}
