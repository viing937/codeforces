#include <iostream>
#include <vector>
using namespace std;

int str2int(const string &s)
{
    int num = 0;
    for ( char ch : s )
        num = num*10+ch-'0';
    return num;
}

int main()
{
    vector<string> alcohol = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    int n;
    cin >> n;
    int ans = 0;
    for ( int i = 0; i < n; ++i )
    {
        string line;
        cin >> line;
        if ( line[0] >= '0' && line[0] <= '9' )
        {
            if ( str2int(line) < 18 ) ans += 1;
        }
        else
        {
            for ( string s : alcohol )
                if ( s == line )
                    ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
