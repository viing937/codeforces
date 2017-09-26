#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int a = count(s.begin(), s.end(), 'A');
    int d = n - a;
    if (a < d)
        cout << "Danik" << endl;
    else if (a > d)
        cout << "Anton" << endl;
    else
        cout << "Friendship" << endl;
    return 0;
}
