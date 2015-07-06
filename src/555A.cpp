#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    int ans = 0;
    cin >> n >> k;
    int assemble = n;
    while ( assemble )
    {
        int m;
        cin >> m;
        vector<int> chain(m);
        for ( int i = 0; i < m; i++ )
            cin >> chain[i];
        if ( chain[0] == 1 )
        {
            for ( int i = 1; i < m; i++ )
                if ( chain[i] != chain[i-1]+1 )
                {
                    ans += (m-i)<<1;
                    break;
                }
        }
        else
            ans += (m<<1) - 1;
        assemble -= m;
    }
    cout << ans << endl;
    return 0;
}
