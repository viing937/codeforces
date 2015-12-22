#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int carry_bit(vector<int> &x, int index)
{
    if ( index >= (int)x.size() )
    {
        x.push_back(4);
        for ( int i = 0; i < index; ++i )
            x[i] = 4;
        return 1;
    }
    else if ( x[index] < 7 )
    {
        x[index] = (x[index]<4) ? 4 : 7;
        for ( int i = 0; i < index; ++i )
            x[i] = 4;
        return 1;
    }
    else
        return 0;
}

void carry(vector<int> &x)
{
    int n = x.size();
    int l = n-1;
    while ( l >= 0 && (x[l] == 4 || x[l] == 7) )
        l -= 1;
    if ( l < 0 )
        return;
    if ( carry_bit(x, l) )
        return;
    for ( int i = l+1; i < n; ++i )
    {
        if ( carry_bit(x, i) )
            return;
    }
    carry_bit(x, n);
    return;
}

long long next(long long x)
{
    vector<int> bits;
    while ( x )
    {
        bits.push_back(x%10);
        x /= 10;
    }
    carry(bits);
    for ( int i = bits.size()-1; i >= 0; --i )
        x = x*10+bits[i];
    return x;
}

int main()
{
    long long l, r;
    cin >> l >> r;
    long long ans = 0;
    while ( l <= r )
    {
        long long t = next(l);
        ans += (min(t, r)-l+1)*t;
        l = t+1;
    }
    cout << ans << endl;
    return 0;
}
