#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if ( n == k )
    {
        cout << "-1" << endl;
        return 0;
    }
    vector<int> result(n+1);
    result[n] = 1, result[1] = k+2>n ? 1 : k+2;;
    for ( int i = 2; i <= 1+k; ++i )
        result[i] = i;
    for ( int i = 2+k; i < n; ++i )
        result[i]  = i+1;
    for ( int i = 1; i < n; ++i )
        cout << result[i] << " ";
    cout << result[n] << "\n";
    return 0;
}
