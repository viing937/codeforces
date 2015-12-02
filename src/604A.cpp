#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<double> m(5), w(5), x = {500, 1000, 1500, 2000, 2500};
    double hs, hu;
    for ( int i = 0; i < 5; ++i )
        cin >> m[i];
    for ( int i = 0; i < 5; ++i )
        cin >> w[i];
    cin >> hs >> hu;
    double ans = 0;
    for ( int i = 0; i < 5; ++i )
        ans += max(0.3*x[i], x[i]-x[i]/250*m[i]-50*w[i]);
    ans += 100*hs-50*hu;
    cout << (int)(ans+0.5) << endl;
    return 0;
}
