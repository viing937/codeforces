#include <iostream>
#include <algorithm>
using namespace std;

bool check(const string &s, int start, int end)
{
    int len = end-start+1;
    if ( len%2 )
        return false;
    for ( int i = 0; i < len/2; ++i )
        if ( s[start+i] != s[start+len/2+i] && s[start+i] != '?' && s[start+len/2+i] != '?' )
            return false;
    return true;
}

int main()
{
    int k;
    string s;
    cin >> s >> k;
    for ( int i = 0; i < k; ++i )
        s.push_back('?');
    int result = 0, len = s.size();
    for ( int i = 0; i < len; ++i )
        for ( int j = i; j < len; ++j )
            if ( check(s, i, j) )
                result = max(result, j-i+1);
    cout << result << '\n';
    return 0;
}
