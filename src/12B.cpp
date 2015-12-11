#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int str_to_int(string &s)
{
    stringstream ss(s);
    int t;
    ss >> t;
    return t;
}

int main()
{
    string a, b;
    cin >> a >> b;
    if ( a.size() != b.size() )
    {
        cout << "WRONG_ANSWER" << endl;
        return 0;
    }

    int n = str_to_int(a), m = str_to_int(b);
    vector<int> cnt(10, 0);
    while ( n )
    {
        cnt[n%10] += 1;
        n /= 10;
    }
    for ( int i = 1; i <= 9; ++i )
    {
        if ( cnt[i] )
        {
            cnt[i] -= 1;
            n = i;
            break;
        }
    }
    for ( int i = 0; i <= 9; ++i )
    {
        while ( cnt[i] )
        {
            cnt[i] -= 1;
            n = n*10+i;
        }
    }
    if ( n == m )
        cout << "OK" << endl;
    else
        cout << "WRONG_ANSWER" << endl;
    return 0;
}
