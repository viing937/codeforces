#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    for ( int i = 0; i < m; ++i )
    {
        char x, y;
        cin >> x >> y;
        int index_x, index_y;
        for ( int j = 0; j < 26; ++j )
        {
            if ( letters[j] == x )
                index_x = j;
            if ( letters[j] == y )
                index_y = j;
        }
        swap(letters[index_x], letters[index_y]);
    }
    for ( unsigned int i = 0; i < s.size(); ++i )
        s[i] = letters[s[i]-'a'];
    cout << s << '\n';
    return 0;
}
