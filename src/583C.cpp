#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int gcd(int a, int b)
{
    int t;
    while ( b )
    {
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> result(n);
    map<int, int> hashmap;
    for ( int i = 0; i < n*n; ++i )
    {
        int t;
        scanf("%d", &t);
        hashmap[t] += 1;
    }
    for ( int i = 0; i < n; ++i )
    {
        result[i] = hashmap.rbegin()->first;
        hashmap[result[i]] -= 1;
        if ( hashmap[result[i]] == 0 )
            hashmap.erase(result[i]);
        for ( int j = 0; j < i; ++j )
        {
            int g = gcd(result[i], result[j]);
            hashmap[g] -= 2;
            if ( hashmap[g] == 0 )
                hashmap.erase(g);
        }
    }
    for ( int i = n-1; i > 0; --i )
        printf("%d ", result[i]);
    printf("%d\n", result[0]);
    return 0;
}
