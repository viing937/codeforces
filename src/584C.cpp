#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    string a, b;
    cin >> a >> b;
    int diff = 0;
    for ( int i = 0; i < n; ++i )
        if ( a[i] != b[i] )
            diff += 1;
    if ( t < diff/2 + diff%2 )
    {
        cout << -1 << '\n';
        return 0;
    }
    string result = a;
    for ( int i = 0; i < n && diff < t; ++i )
    {
        if ( a[i] == b[i] )
        {
            result[i] = (a[i]-'a'+1)%26+'a';
            t -= 1;
        }
    }
    int cnt_a = diff-t, cnt_b = 2*t-diff;
    int i = 0;
    while ( cnt_a )
    {
        while ( i < n && a[i] == b[i] )
            i += 1;
        result[i] = a[i];
        i += 1;
        while ( i < n && a[i] == b[i] )
            i += 1;
        result[i] = b[i];
        i += 1;
        cnt_a -= 1;
    }
    while ( cnt_b )
    {
        while ( i < n && a[i] == b[i] )
            i += 1;
        while ( result[i] == a[i] || result[i] == b[i] )
            result[i] = (result[i]-'a'+1)%26+'a';
        i += 1;
        cnt_b -= 1;
    }
    cout << result << endl;
    return 0;
}
