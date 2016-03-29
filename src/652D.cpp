#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define MAXN 400000

void myhash(vector< pair< pair<int, int>, int> > &a)
{
    set<int> t;
    for ( int i = 0; i < (int)a.size(); ++i )
    {
        t.insert(a[i].first.first);
        t.insert(a[i].first.second);
    }
    map<int, int> v;
    int index = 1;
    for ( auto s : t )
        v[s] = index++;
    for ( int i = 0; i < (int)a.size(); ++i )
    {
        a[i].first.first = v[a[i].first.first];
        a[i].first.second = v[a[i].first.second];
    }
    return;
}

int lowbit(int x)
{
    return x&-x;
}

int read(int x, const vector<int> &tree)
{
    int result = 0;
    while ( x )
    {
        result += tree[x];
        x -= lowbit(x);
    }
    return result;
}

void inc(int x, vector<int> &tree)
{
    while ( x < MAXN )
    {
        tree[x] += 1;
        x += lowbit(x);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector< pair< pair<int, int>, int> > seg(n);
    for ( int i = 0; i < n; ++i )
    {
        cin >> seg[i].first.second >> seg[i].first.first;
        seg[i].second = i;
    }

    myhash(seg);
    sort(seg.begin(), seg.end());

    vector<int> tree(MAXN), ans(n);
    for ( int i = 0; i < n; ++i )
    {
        ans[seg[i].second] = read(seg[i].first.first-1, tree)-read(seg[i].first.second, tree);
        inc(seg[i].first.second, tree);
    }

    for ( int i = 0; i < n; ++i )
        cout << ans[i] << '\n';

    return 0;
}
