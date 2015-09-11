#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if ( n > m )
    {
        cout << "YES" << endl;
        return 0;
    }
    bool result = false;
    set<int> dp = {0};
    for ( int i = 0; i < n; ++i )
    {
        int a;
        cin >> a;
        set<int> tmp(dp);
        for ( auto item : tmp )
        {
            item = (item+a)%m;
            if ( item == 0 )
                result = true;
            dp.insert(item);
        }
    }
    if ( result )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
