#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for ( int i = 0; i < n; ++i )
    {
        if ( i > 0 && i%2 == 0 && n-i > 1 )
            cout << "-";
        cout << s[i];
    }
    cout << endl;
    return 0;
}
