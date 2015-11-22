#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> d(3);
    cin >> d[0] >> d[1] >> d[2];
    sort(d.begin(), d.end());
    cout << min(d[0]+d[1]+d[2], 2*(d[0]+d[1])) << endl;
    return 0;
}
