#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++)
    {
        vector<long long> c(3);
        cin >> c[0] >> c[1] >> c[2];
        sort(c.begin(), c.end());
        if (c[0] + c[2] > c[1])
            cout << accumulate(c.begin(), c.end(), (long long)0) / 2 << endl;
        else
            cout << c[0] + c[2] << endl;
    }
    return 0;
}