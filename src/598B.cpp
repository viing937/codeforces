#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    while ( m-- )
    {
        int l, r, k;
        cin >> l >> r >> k;
        l -= 1, r -= 1;
        int len = r-l+1;
        string new_s(s);
        for ( int i = 0; i < len; ++i )
            new_s[l+(i+k)%len] = s[l+i];
        s = new_s;
    }
    cout << s << endl;
    return 0;
}
