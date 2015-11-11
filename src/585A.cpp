#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n), d(n), p(n);
    for ( int i = 0; i < n; ++i )
        cin >> v[i] >> d[i] >> p[i];
    vector<int> result;
    for ( int i = 0; i < n; ++i )
    {
        if ( p[i] < 0 )
            continue;
        result.push_back(i+1);
        long long acc = 0;
        for ( int j = i+1; j < n; ++j )
        {
            if ( p[j] < 0 )
                continue;
            p[j] -= v[i] > 0 ? v[i]-- : 0;
            p[j] -= acc;
            if ( p[j] < 0 )
                acc += d[j];
        }
    }
    cout << result.size() << '\n';
    for ( unsigned int i = 0; i < result.size()-1; ++i )
        cout << result[i] << ' ';
    cout << result.back() << '\n';
    return 0;
}
