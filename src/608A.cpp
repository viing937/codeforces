#include <iostream>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int result = s;
    for ( int i = 0; i < n; ++i )
    {
        int f, t;
        cin >> f >> t;
        result = max(result, s+max(0, t-(s-f)));
    }
    cout << result << endl;
    return 0;
}
