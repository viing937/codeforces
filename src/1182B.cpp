#include <iostream>
#include <vector>
using namespace std;

pair<int, int> center(const vector<string> &p) {
    int h = p.size(), w = p[0].size();
    for (int i = 1; i < h-1; i++) {
        for (int j = 1; j < w-1; j++) {
            if (p[i][j] == '*' &&
                p[i-1][j] == p[i][j] && p[i+1][j] == p[i][j] &&
                p[i][j-1] == p[i][j] && p[i][j+1] == p[i][j]) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

bool check_plus(const vector<string> &p) {
    int h = p.size(), w = p[0].size();
    auto c = center(p);

    if (c.first < 0)
        return false;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (p[i][j] == '*' && i != c.first && j != c.second) {
                return false;
            }
        }
    }

    int b;

    for (int i = c.first; i >= 0 && p[i][c.second] == '*'; i--)
        b = i;
    for (int i = b-1; i >= 0; i--)
        if (p[i][c.second] == '*')
            return false;

    for (int i = c.first; i < h && p[i][c.second] == '*'; i++)
        b = i;
    for (int i = b+1; i < h; i++)
        if (p[i][c.second] == '*')
            return false;

    for (int i = c.second; i >= 0 && p[c.first][i] == '*'; i--)
        b = i;
    for (int i = b-1; i >= 0; i--)
        if (p[c.first][i] == '*')
            return false;

    for (int i = c.second; i < w && p[c.first][i] == '*'; i++)
        b = i;
    for (int i = b+1; i < w; i++)
        if (p[c.first][i] == '*')
            return false;

    return true;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> p(h);
    for (int i = 0; i < h; i++)
        cin >> p[i];

    if (check_plus(p))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}