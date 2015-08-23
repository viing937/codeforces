#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Order
{
    int p;
    int q;
};

int main()
{
    map<int, int> buy, sell;
    int n, s;
    cin >> n >> s;
    for ( int i = 0; i < n; ++i )
    {
        char d;
        int p, q;
        cin >> d >> p >> q;
        if ( d == 'S' )
            sell[p] += q;
        else if ( d == 'B' )
            buy[p] += q;
    }
    vector<Order> result(s);
    int index;
    index = 0;
    for ( auto it = sell.begin(); it != sell.end() && index < s; ++it )
    {
        result[index].p = it->first;
        result[index].q = it->second;
        index += 1;
    }
    for ( int i = index-1; i >= 0; --i )
        cout << "S " << result[i].p << " " << result[i].q << "\n";
    index = 0;
    for ( auto it = buy.rbegin(); it != buy.rend() && index < s; ++it )
    {
        result[index].p = it->first;
        result[index].q = it->second;
        index += 1;
    }
    for ( int i = 0; i < index; ++i )
        cout << "B " << result[i].p << " " << result[i].q << "\n";
    return 0;
}
