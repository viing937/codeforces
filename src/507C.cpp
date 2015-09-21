#include <iostream>
using namespace std;

int main()
{
    int h;
    long long n;
    cin >> h >> n;
    n = n+(1ll<<h)-1;
    long long result = 0;
    for ( int i = 0; i < h; ++i )
    {
        if ( ((n>>i)&1) == ((n>>(i+1))&1) )
            result += (1ll<<(i+1))-1;
    }
    cout << result+h << endl;
    return 0;
}
