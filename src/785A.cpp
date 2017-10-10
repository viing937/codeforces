#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;
    for (int i = 0; i < n; i++) {
        string p;
        cin >> p;
        if (p == "Tetrahedron")
            result += 4;
        else if (p == "Cube")
            result += 6;
        else if (p == "Octahedron")
            result += 8;
        else if (p == "Dodecahedron")
            result += 12;
        else if (p == "Icosahedron")
            result += 20;
    }
    cout << result << endl;
    return 0;
}
