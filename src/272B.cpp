#include <iostream>
#include <map>
using namespace std;

int f(int x)
{
    if ( x == 0 )
        return 0;
    else if ( x%2 == 0 )
        return f(x/2);
    else
        return f(x/2)+1;
}

int main()
{
    int n;
    cin >> n;
    map<int, long long> cnt;
    for ( int i = 0; i < n; ++i )
    {
        int tmp;
        cin >> tmp;
        cnt[f(tmp)] += 1;
    }
    long long ans = 0;
    for ( auto it = cnt.begin(); it != cnt.end(); ++it )
    {
        if ( it->second%2 )
            ans += (it->second-1)/2*(it->second);
        else
            ans += (it->second)/2*(it->second-1);
    }
    cout << ans << endl;
    return 0;
}
