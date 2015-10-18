#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int avg = n/k, result = 0;
    map<int, int> count;
    for ( int i = 0; i < n; ++i )
    {
        int t;
        scanf("%d", &t);
        count[t] += 1;
    }
    for ( auto it = count.begin(); it != count.end(); ++it )
        if ( it->second > avg )
            result += it->second-avg;
    printf("%d\n", result);
    return 0;
}
