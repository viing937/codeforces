#include <iostream>
using namespace std;

int main()
{
    long long k, a, b;
    cin >> k >> a >> b;
    long long first;
    if ( a%k == 0 )
        first = a;
    else
        first = a+(k-(a%k+k)%k);
    if ( first > b )
        cout << 0 << endl;
    else
        cout << (b-first)/k+1 << endl;
    return 0;
}
