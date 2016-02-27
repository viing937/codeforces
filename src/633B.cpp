#include <iostream>
using namespace std;

int cal(int x)
{
    int t = 5, s = 0;
    while ( t <= x )
    {
        s += x/t;
        t *= 5;
    }
    return s;
}

int binary_search(int l, int r, int t)
{
    if ( l > r )
        return -1;
    int m = (l+r)/2;
    int cnt = cal(m);
    if ( cnt >= t && cal(m-1) < t )
        return m;
    else if ( cnt < t )
        return binary_search(m+1, r, t);
    else
        return binary_search(l, m-1, t);
}

int main()
{
    int m;
    cin >> m;
    int l = binary_search(1, 500000, m), r = binary_search(1, 500000, m+1);
    if ( cal(l) != m )
        cout << 0 << endl;
    else
    {
        cout << r-l << '\n';
        for ( int i = l; i < r; ++i )
            cout << i << (i==r-1 ? '\n' : ' ');
    }
    return 0;
}
