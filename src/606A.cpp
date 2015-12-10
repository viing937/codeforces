#include <iostream>
using namespace std;

int main()
{
    int a[3], x[3];
    for ( int i = 0; i < 3; ++i )
        cin >> a[i];
    for ( int i = 0; i < 3; ++i )
        cin >> x[i];
    int cnt1 = 0, cnt2 = 0;
    for ( int i = 0; i < 3; ++i )
    {
        if ( a[i] > x[i] )
            cnt1 += (a[i]-x[i])/2;
        else
            cnt2 += x[i]-a[i];
    }
    if ( cnt1 >= cnt2 )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
