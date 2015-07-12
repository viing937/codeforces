#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> cups(2*n);
    for ( int i = 0; i < 2*n; i++ )
        cin >> cups[i];
    sort(cups.begin(), cups.end());
    double b, g;
    b = min(cups[0]*2, cups[n]);
    g = b/2.0;
    if ( (b+g)*n > w )
        cout << w << endl;
    else
        cout << setiosflags(ios::fixed) << setprecision(10) << (b+g)*n << endl;
    return 0;
}
