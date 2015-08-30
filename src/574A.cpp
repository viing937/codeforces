#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i];
    sort(a.begin()+1, a.end(), greater<int>());
    if ( a[0] > a[1] )
    {
        cout << 0 << endl;
        return 0;
    }
    int sum = a[0];
    for ( int i = 1; i < n; ++i )
    {
        sum += a[i];
        if ( (i+1 < n && sum/(i+1) >= a[i+1]) || i+1 == n )
        {
            if ( sum%(i+1) < 2 )
                cout << sum/(i+1)+1-a[0] << endl;
            else
                cout << sum/(i+1)+2-a[0] << endl;
            break;
        }
    }
    return 0;
}
