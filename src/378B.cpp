#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i] >> b[i];
    string aa(n, '0'), bb(n, '0');
    for ( int i = 0; i < n/2; ++i )
        aa[i] = bb[i] = '1';
    for ( int i = 0, idx1 = 0, idx2 = 0; i < n; ++i )
    {
        if ( idx1 < n && idx2 < n )
        {
            if ( a[idx1] < b[idx2] )
                aa[idx1++] = '1';
            else
                bb[idx2++] = '1';
        }
        else if ( idx1 < n )
            aa[idx1++] = '1';
        else if ( idx2 < n )
            bb[idx2++] = '1';
    }
    cout << aa << '\n' << bb << endl;
    return 0;
}
