#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    map<int, int> count;
    for ( int i = 0; i < n; ++i )
    {
        int t;
        scanf("%d", &t);
        count[t] += 1;
    }
    int result = 0;
    while ( count.size() )
    {
        auto it = count.begin();
        if ( it->second %2 )
            result += 1;
        if ( it->second /2 )
            count[it->first+1] += it->second / 2;
        count.erase(it);
    }
    printf("%d\n", result);
    return 0;
}
