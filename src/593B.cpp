#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int x1, x2;
    scanf("%d%d", &x1, &x2);
    vector< pair<long long, long long> > arr;
    for ( int i = 0; i < n; ++i )
    {
        int k, b;
        scanf("%d%d", &k, &b);
        arr.push_back(make_pair((long long)k*x1+b, (long long)k*x2+b));
    }
    sort(arr.begin(), arr.end());
    for ( int i = 0; i < n-1; ++i )
    {
        if ( arr[i].first < arr[i+1].first && arr[i].second > arr[i+1].second )
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
