#include <iostream>
#include <vector>
#define MAXN 10000000
using namespace std;

vector<int> getprime()
{
    vector<int> prime(MAXN, 1);
    prime[0] = prime[1] = 0;
    for ( int i = 2; i < MAXN; ++i )
    {
        if ( prime[i] )
            for ( int j = i+i; j < MAXN; j += i )
                prime[j] = 0;
        prime[i] += prime[i-1];
    }
    return prime;
}

int reverse(int number)
{
    int result = 0;
    while ( number )
    {
        result = result*10+number%10;
        number /= 10;
    }
    return result;
}

vector<int> getpalnum()
{
    vector<int> palnum(MAXN);
    palnum[0] = 0;
    for ( int i = 1; i < MAXN; ++i )
    {
        if ( i == reverse(i) )
            palnum[i] = palnum[i-1]+1;
        else
            palnum[i] = palnum[i-1];
    }
    return palnum;
}

int main()
{
    vector<int> prime(getprime()), palnum(getpalnum());
    int p, q;
    cin >> p >> q;
    int result = 0;
    for ( int i = 1; i < MAXN; ++i )
    {
        if ( prime[i] <= p*palnum[i]/q )
            result = i;
    }
    if ( result > 0 )
        cout << result << endl;
    else
        cout << "Palindromic tree is better than splay tree" << endl;
    return 0;
}
