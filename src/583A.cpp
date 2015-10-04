#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<bool> hor(n+1, false), ver(n+1, false);
    vector<int> result;
    for ( int i = 1; i <= n*n; ++i )
    {
        int h, v;
        scanf("%d%d", &h, &v);
        if ( !hor[h] && !ver[v] )
        {
            hor[h] = ver[v] = true;
            result.push_back(i);
        }
    }
    for ( int i = 0; i < (int)result.size()-1; ++i )
        printf("%d ", result[i]);
    printf("%d\n", result.back());
    return 0;
}
