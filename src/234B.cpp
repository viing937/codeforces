#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, k;
    in >> n >> k;
    vector< pair<int, int> > a;
    for ( int i = 1; i <= n; ++i )
    {
        int tmp;
        in >> tmp;
        a.push_back(make_pair(tmp, i));
    }
    sort(a.begin(), a.end(), greater< pair<int, int> >());
    out << a[k-1].first << '\n';
    for ( int i = 0; i < k-1; ++i )
        out << a[i].second << ' ';
    out << a[k-1].second << '\n';
    return 0;
}
