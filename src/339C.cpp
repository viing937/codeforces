#include <iostream>
#include <vector>
using namespace std;

int m;
string s;
vector<int> seq;

bool dfs(int a, int b, int c, int sig)
{
    if ( m == c )
        return true;
    for ( int i = 1; i <= 10; ++i )
    {
        if ( s[i-1] == '1' && i != b && (a == 0 || (a+sig*i)*a < 0) )
        {
            seq.push_back(i);
            if ( dfs(a+sig*i, i, c+1, -sig) )
                return true;
            seq.pop_back();
        }
    }
    return false;
}

int main()
{
    cin >> s >> m;
    
    if ( dfs(0, 0, 0, 1) )
    {
        cout << "YES" << '\n';
        for ( int i = 0; i < m; ++i )
            cout << seq[i] << ' ';
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
