#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int result = 0;
    while ( x )
    {
        result += x%2;
        x /= 2;
    }
    cout << result << endl;
    return 0;
}
