#include <iostream>
#include <vector>
#define MAXN 1000
using namespace std;

int main()
{
    vector<bool> primeflag(MAXN+1, true);
    primeflag[0] = primeflag[1] = false;
    for ( int i = 2; i <= MAXN; ++i )
        if ( primeflag[i] )
            for ( int j = i+i; j <= MAXN; j += i )
                primeflag[j] = false;
    vector<int> prime;
    for ( int i = 0; i <= MAXN; ++i )
        if ( primeflag[i] )
            prime.push_back(i);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for ( int i = 0; i < (int)prime.size()-1; ++i )
    {
        int t = prime[i]+prime[i+1]+1;
        if ( t > n ) break;
        if ( primeflag[t] ) ans += 1;
    }
    if ( ans >= k ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
