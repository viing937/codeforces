#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int sum, limit;
    cin >> sum >> limit;
    vector<int> result;
    while ( limit )
    {
        int t = limit&(limit^(limit-1));
        if ( sum >= t )
        {
            sum -= t;
            result.push_back(limit);
        }
        limit -= 1;
    }
    if ( sum == 0 )
    {
        cout << result.size() << '\n';
        for ( unsigned int i = 0; i < result.size()-1; ++i )
            cout << result[i] << ' ';
        cout << result.back() << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
