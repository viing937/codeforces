#include <iostream>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    int cnt = 0;
    for ( int i = 0; i < n; ++i )
    {
        string op;
        long long d;
        cin >> op >> d;
        if ( op[0] == '+' )
            x += d;
        else if ( op[0] == '-' && x >= d )
            x -= d;
        else if ( op[0] == '-' && x < d )
            cnt += 1;
    }
    cout << x << ' ' << cnt << endl;
    return 0;
}
