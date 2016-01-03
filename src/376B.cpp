#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> C(n+1, 0);
    for ( int i = 0; i < m; ++i )
    {
        int a, b, c;
        cin >> a >> b >> c;
        C[a] -= c;
        C[b] += c;
    }
    for ( int i = 1; i <= n; ++i )
        if ( C[i] > 0 )
            C[0] += C[i];
    cout << C[0] << endl;
    return 0;
}
