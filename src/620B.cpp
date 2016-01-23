#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> count(10, 0);
    for ( int i = a; i <= b; ++i )
    {
        int t = i;
        while ( t )
        {
            count[t%10] += 1;
            t /= 10;
        }
    }
    vector<int> segment = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int ans = 0;
    for ( int i = 0; i < 10; ++i )
        ans += segment[i]*count[i];
    cout << ans << endl;
    return 0;
}
