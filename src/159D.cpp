#include <iostream>
#include <vector>
using namespace std;

bool ispalindromic(const string &s, int l, int r)
{
    while ( l < r )
        if ( s[l++] != s[r--] )
            return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> left(n, 0), right(n, 0);
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = i; j < n; ++j )
        {
            if ( ispalindromic(s, i, j) )
            {
                left[j] += 1;
                right[i] += 1;
            }
        }
    }
    for ( int i = n-1; i > 0; --i )
        right[i-1] += right[i];
    long long ans = 0;
    for ( int i = 0; i < n-1; ++i )
        ans += left[i]*right[i+1];
    cout << ans << endl;
    return 0;
}
