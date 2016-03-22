#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> t(1050);
    for ( int i = 0; i < n; ++i )
    {
        int ball;
        cin >> ball;
        t[ball] = 1;
    }
    for ( int i = 3; i <= 1000; ++i )
    {
        if ( t[i-2] && t[i-1] && t[i] )
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
