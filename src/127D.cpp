#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1000009

int main()
{
    string s;
    cin >> s;
    int len = s.size();

    vector<bool> mark(len, false);
    vector<int> f(len, 0);
    int k = 0;
    for ( int i = 1; i < len; ++i )
    {
        while ( k && s[i] != s[k] )
            k = f[k-1];
        if ( s[i] == s[k] )
            k += 1;
        if ( i < len-1 )
            mark[k] = true;
        f[i] = k;
    }
    mark[0] = true;
    k = f[len-1];
    while ( k && !mark[k] )
        k = f[k-1];
    if ( k )
        cout << s.substr(0, k) << endl;
    else
        cout << "Just a legend" << endl;
    return 0;
}
