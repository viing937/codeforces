#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int> &a, bool reverse = false)
{
    int n = a.size();
    if ( reverse )
        for ( int i = n-1; i >= 0; --i )
            cout << a[i] << ' ';
    else
        for ( int i = 0; i < n; ++i )
            cout << a[i] << ' ';
    return;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if ( n > a*b )
        cout << -1 << endl;
    else
    {
        int cur = 1;
        vector< vector<int> > g(a, vector<int>(b));
        for ( int i = 0; i < a; ++i )
        {
            for ( int j = 0; j < b; ++j )
            {
                if ( cur <= n )
                    g[i][j] = cur++;
                else
                    g[i][j] = 0;
            }
        }
        for ( int i = 0; i < a; ++i )
        {
            display(g[i], b%2 == 0 && i%2 == 1 );
            cout << '\n';
        }
    }
    return 0;
}
