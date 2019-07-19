#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long l = 1, r = n;
    while (true)
    {
        long long m = l + (r - l) / 2;
        long long re = (1 + m) * m / 2 - (n - m);
        if (re == k)
        {
            cout << (n - m) << endl;
            break;
        }
        else if (re < k)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return 0;
}