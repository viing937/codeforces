#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int na, nb;
    cin >> na >> nb;
    int k, m;
    cin >> k >> m;
    vector<int> a(na), b(nb);
    for ( int i = 0; i < na; ++i )
        cin >> a[i];
    for ( int i = 0; i < nb; ++i )
        cin >> b[i];
    if ( a[k-1] < b[nb-m] )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
