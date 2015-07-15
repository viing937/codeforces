#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int, int> c;
    for ( int i = 0; i < n; i++ )
    {
        scanf("%d", &a[i]);
        c[a[i]]++;
    }
    int max_times = 0;
    for ( auto it = c.begin(); it != c.end(); it++ )
        if ( it->second > max_times )
            max_times = it->second;
    map<int, int> left_index, right_index;
    for ( int i = 0; i < n; i++ )
        right_index[a[i]] = i;
    for ( int i = n-1; i >= 0; i-- )
        left_index[a[i]] = i;
    int l = 0, r = n-1;
    for ( auto it = c.begin(); it != c.end(); it++ )
        if ( it->second == max_times && right_index[it->first]-left_index[it->first] < r-l )
            l = left_index[it->first], r = right_index[it->first];
    printf("%d %d\n", l+1, r+1);
    return 0;
}
