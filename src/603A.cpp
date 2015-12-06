#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<char> as;
    as.push_back(s[0]);
    for ( int i = 1; i < n; ++i )
        if ( as.back() != s[i] )
            as.push_back(s[i]);
    cout << min(n, (int)as.size()+2) << endl;
    return 0;
}
