#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> prev(n, 1), follow(n, 1);
    for ( int i = 1; i < n; ++i )
    {
        prev[i] = (prev[i-1]*7) % MOD;
        follow[i] = (follow[i-1]*27) % MOD;
    }
    long long result = 0;
    for ( int i = 0; i < n; ++i )
        result = (result+((prev[i]*follow[n-i-1])%MOD*20)%MOD)%MOD;
    cout << result << endl;
    return 0;
}
