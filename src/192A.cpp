#include <iostream>
#include <cmath>
using namespace std;

bool binary(int l, int r, int target)
{
    if ( l > r )
        return false;
    int k1 = (l+r)/2;
    int k2 = sqrt(target-k1*(k1+1));
    if ( k2 > 0 && k1*(k1+1)+k2*(k2+1) == target )
        return true;
    else
        return binary(l, k1-1, target) || binary(k1+1, r, target);
}

int main()
{
    int n;
    cin >> n;
    if ( binary(1, sqrt(n), 2*n) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
