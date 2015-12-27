#include <iostream>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int lena = a.size(), lenb = b.size(), diff = lenb-lena+1;
    long long ans = 0, x = 0;
    for ( int i = 0; i < diff; ++i )
        x += b[i]-'0';
    for ( int i = 0; i < lena; ++i )
    {
        ans += (a[i]=='0')?x:diff-x;
        x += b[diff+i]-b[i];
    }
    cout << ans << endl;
    return 0;
}
