#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int distinguish()
{
    string s;
    cin >> s;
    if ( s[0] == s[1] && s[1] == s[3] && s[3] == s[4] && s[4] == s[6] && s[6] == s[7] )
        return 0;
    else if ( s[0] > s[1] && s[1] > s[3] && s[3] > s[4] && s[4] > s[6] && s[6] > s[7] )
        return 1;
    else
        return 2;
}

int main()
{
    int n;
    cin >> n;
    vector<string> names(n);
    vector< vector<int> > types(3, vector<int>(n, 0));
    for ( int i = 0; i < n; ++i )
    {
        int s;
        cin >> s >> names[i];
        for ( int j = 0; j < s; ++j )
            types[distinguish()][i] += 1;
    }

    int max_value;
    bool first;

    max_value = *max_element(types[0].begin(), types[0].end());
    first = true;
    cout << "If you want to call a taxi, you should call: ";
    for ( int i = 0; i < n; ++i )
    {
        if ( types[0][i] == max_value )
        {
            cout << (first ? names[i] : ", "+names[i]);
            first = false;
        }
    }
    cout << ".\n";

    max_value = *max_element(types[1].begin(), types[1].end());
    first = true;
    cout << "If you want to order a pizza, you should call: ";
    for ( int i = 0; i < n; ++i )
    {
        if ( types[1][i] == max_value )
        {
            cout << (first ? names[i] : ", "+names[i]);
            first = false;
        }
    }
    cout << ".\n";

    max_value = *max_element(types[2].begin(), types[2].end());
    first = true;
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for ( int i = 0; i < n; ++i )
    {
        if ( types[2][i] == max_value )
        {
            cout << (first ? names[i] : ", "+names[i]);
            first = false;
        }
    }
    cout << ".\n";
    return 0;
}
