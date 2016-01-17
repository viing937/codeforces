#include <iostream>
#include <string>
using namespace std;

bool isbeautiful(string &s)
{
    int cnt = 0;
    for ( auto ch : s )
    {
        if ( ch >= '2' && ch <= '9' )
            return false;
        else if ( ch == '1' )
            cnt += 1;
    }
    return cnt>1 ? false : true;
}

int main()
{
    int n;
    cin >> n;
    string base = "1";
    int cnt = 0;
    for ( int i = 0; i < n; ++i )
    {
        string a;
        cin >> a;
        if ( base == "1" && !isbeautiful(a) )
            base = a;
        else
            cnt += a.size()-1;
        if ( a[0] == '0' )
        {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << base;
    while ( cnt-- )
        cout << 0;
    cout << endl;
    return 0;
}
