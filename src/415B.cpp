#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    for ( int i = 0; i < n; ++i )
    {
        cin >> x[i];
        x[i] = x[i]*a%b/a;
    }
    for ( int i = 0; i < n-1; ++i )
        cout << x[i] << ' ';
    cout << x[n-1] << '\n';
    return 0;
}
