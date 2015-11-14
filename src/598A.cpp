#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while ( t-- )
    {
        long long n, result;
        cin >> n;
        result = (1+n)*n/2;
        long long tmp = 1;
        while ( tmp <= n )
        {
            tmp *= 2;
            result -= tmp;
        }
        cout << result << '\n';
    }
    return 0;
}
