#include <cstdio>
#include <vector>
#define MAXNUM 5000000
using namespace std;

vector<int> getPrime()
{
    vector<int> prime;
    vector<bool> isPrime(MAXNUM+1, true);
    isPrime[0] = isPrime[1] = false;
    for ( int i = 2; i <= MAXNUM; i++ )
    {
        if ( isPrime[i] )
            prime.push_back(i);
        for ( int j = 0; j < (int)prime.size(); j++ )
        {
            if ( i*prime[j] > MAXNUM )
                break;
            isPrime[i*prime[j]] = false;
            if ( i%prime[j] == 0 )
                break;
        }
    }
    return prime;
}

vector<int> countPrime()
{
    vector<int> prime = getPrime();
    vector<int> count(MAXNUM+1, 0);
    for ( int i = 1; i <= MAXNUM; i++ )
    {
        for ( int j = 0; j < (int)prime.size(); j++ )
        {
            if ( i*prime[j] <= MAXNUM  )
                count[i*prime[j]] = count[i]+1;
            else
                break;
        }
    }
    for ( int i = 1; i <= MAXNUM; i++ )
    {
        count[i] += count[i-1];
    }
    return count;
}

int main()
{
    vector<int> count = countPrime();
    int t;
    scanf("%d", &t);
    for ( int i = 0; i < t; i++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", count[a]-count[b]);
    }
    return 0;
}
