#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &a[i]);

    vector< pair<int, pair<int, int> > > op(m);
    for ( int i = 0; i < m; ++i )
    {
        int t, r;
        scanf("%d%d", &t, &r);
        op[i] = make_pair(r, make_pair(i, t));
    }

    sort(op.begin(), op.end(), greater< pair<int, pair<int, int> > >());
    if ( op[0].second.second == 1 )
        sort(a.begin(), a.begin()+op[0].first, less<int>());
    else
        sort(a.begin(), a.begin()+op[0].first, greater<int>());

    int last = 0, l = 0, r = op[0].first-1;
    bool rev = false;
    vector<int> tmp(a.begin(), a.begin()+op[0].first);
    for ( int i = 1; i < m; ++i )
    {
        if ( op[i].second.first <= op[last].second.first )
            continue;
        else
        {
            if ( rev )
            {
                for ( int j = 0; j < op[last].first-op[i].first; ++j )
                    a[op[last].first-j-1] = tmp[l+j];
                l += op[last].first - op[i].first;
            }
            else
            {
                for ( int j = 0; j < op[last].first-op[i].first; ++j )
                    a[op[last].first-j-1] = tmp[r-j];
                r -= op[last].first - op[i].first;
            }
            if ( op[i].second.second != op[last].second.second )
                rev = !rev;
            last = i;
        }
    }

    if ( !rev )
        for ( int i = 0; i < op[last].first; ++i )
            a[i] = tmp[l+i];
    else
        for ( int i = 0; i < op[last].first; ++i )
            a[i] = tmp[r-i];

    for ( int i = 0; i < n; ++i )
    {
        if ( i == n-1 )
            printf("%d\n", a[i]);
        else
            printf("%d ", a[i]);
    }
    return 0;
}
