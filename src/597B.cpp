#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if ( a.second == b.second )
        return a.first > b.first;
    else
        return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector< pair<int, int> > segments;
    for ( int i = 0; i < n; ++i )
    {
        int l, r;
        cin >> l >> r;
        segments.push_back(make_pair(l, r));
    }
    sort(segments.begin(), segments.end(), cmp);
    int result = 1, pos = segments[0].second;
    for ( int i = 1; i < n; ++i )
    {
        if ( segments[i].first > pos )
        {
            pos = segments[i].second;
            result += 1;
        }
    }
    cout << result << endl;
    return 0;
}
