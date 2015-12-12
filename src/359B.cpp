#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(2*n);
    for ( int i = 0; i < 2*n; ++i )
        a[i] = i+1;
    for ( int i = 1; i <= k; ++i )
        swap(a[2*i], a[2*i+1]);
    for ( int i = 0; i < 2*n-1; ++i )
        cout << a[i] << ' ';
    cout << a.back() << '\n';
    return 0;
}
