#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    vector<int> dic_a(26, 0), dic_b(26, 0), dic_c(26, 0);
    for ( auto ch : a ) dic_a[ch-'a'] += 1;
    for ( auto ch : b ) dic_b[ch-'a'] += 1;
    for ( auto ch : c ) dic_c[ch-'a'] += 1;

    int max_x = a.size()/b.size();
    for ( int i = 0; i < 26; ++i )
        if ( dic_b[i] != 0 )
            max_x = min(max_x, dic_a[i]/dic_b[i]);

    int x = 0, y = 0;
    for ( int i = 0; i <= max_x; ++i )
    {
        int xx = i, yy = a.size()/c.size();
        for ( int j = 0; j < 26; ++j )
            if ( dic_c[j] != 0 )
                yy = min(yy, (dic_a[j]-dic_b[j]*xx)/dic_c[j]);
        if ( xx+yy > x+y )
            x = xx, y = yy;
    }

    for ( int i = 0; i < x; ++i )
        cout << b;
    for ( int i = 0; i < y; ++i )
        cout << c;
    for ( int i = 0; i < 26; ++i )
        for ( int j = 0; j < dic_a[i]-x*dic_b[i]-y*dic_c[i]; ++j )
            cout << char('a'+i);
    cout << '\n';
    return 0;
}
