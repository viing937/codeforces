#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isprime(int n)
{
    for ( int i = 2; i <= sqrt(n); ++i )
        if ( n%i == 0 )
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> result;
    for ( int i = 2; i <= n; ++i )
    {
        if ( !isprime(i) )
            continue;
        int p = i;
        while ( p <= n )
        {
            result.push_back(p);
            p *= i;
        }
    }
    cout << result.size() << endl;
    for ( unsigned int i = 0; i < result.size(); ++i )
    {
        if ( i == 0 )
            cout << result[i];
        else
            cout << " " << result[i];
    }
    cout << endl;
    return 0;
}
