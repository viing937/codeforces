#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool is_prime(int a)
{
    if ( a < 2 )
        return false;
    for ( int i = 2; i <= sqrt(a); ++i )
    {
        if ( a%i == 0 )
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if ( n == 3 ) {cout << "1\n3" << '\n'; return 0;}
    if ( n == 4 ) {cout << "2\n2 2" << '\n'; return 0;}
    if ( n == 5 ) {cout << "2\n2 3" << "\n"; return 0;}
    vector<int> result;
    if ( n%2 )
    {
        result.push_back(3);
        n -= 3;
    }
    for ( int i = 2; 1; ++i )
    {
        if ( is_prime(i) && is_prime(n-i) )
        {
            result.push_back(i);
            result.push_back(n-i);
            break;
        }
    }
    if ( result.size() == 2 )
        cout << "2\n" << result[0] << ' ' << result[1] << '\n';
    else
        cout << "3\n" << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';
    return 0;
}
