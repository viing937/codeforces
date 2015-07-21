#include <iostream>
#include <vector>
#define MOD 1000000007
#define MAXN 1005
using namespace std;

int main()
{
    vector< vector<long long> > comb(MAXN, vector<long long>(MAXN));
    for ( int i = 0; i < MAXN; i++ )
    {
        comb[i][0] = 1;
        for ( int j = 1; j <= i; j++ )
            comb[i][j] = (comb[i-1][j-1]+comb[i-1][j]) % MOD;
    }
    int k;
    cin >> k;
    vector<int> c(k);
    for ( int i = 0; i < k; i++ )
        cin >> c[i];
    long long result = 1;
    int total = 0;
    for ( int i = 0; i < k; i++ )
    {
        result = (result * comb[total+c[i]-1][c[i]-1]) % MOD;
        total += c[i];
    }
    cout << result << endl;
    return 0;
}
