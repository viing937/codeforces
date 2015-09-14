#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> w(n), h(n);
    int w_sum = 0, h_max_idx = 0;
    for ( int i = 0; i < n; ++i )
    {
        cin >> w[i] >> h[i];
        w_sum += w[i];
        if ( h[h_max_idx] <= h[i] )
            h_max_idx = i;
    }
    vector<int> result(n);
    for ( int i = 0; i < n; ++i )
    {
        if ( h_max_idx != i )
            result[i] = (w_sum-w[i])*h[h_max_idx];
        else
        {
            int h_2nd_idx;
            if ( h_max_idx != 0 )
                h_2nd_idx = 0;
            else
                h_2nd_idx = 1;
            for ( int j = 0; j < n; ++j )
                if ( j != h_max_idx && h[h_2nd_idx] <= h[j] )
                    h_2nd_idx = j;
            result[i] = (w_sum-w[i])*h[h_2nd_idx];
        }
    }
    cout << result[0];
    for ( int i = 1; i < n; ++i )
        cout << " " << result[i];
    cout << endl;
    return 0;
}
