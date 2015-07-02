#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int min_1, min_2, min_3;
    int max_1, max_2, max_3;
    cin >> n >> min_1 >> max_1
             >> min_2 >> max_2
             >> min_3 >> max_3;
    min_1 = min(max_1, n-min_2-min_3);
    min_2 = min(max_2, n-min_1-min_3);
    min_3 = min(max_3, n-min_1-min_2);
    cout << min_1 << " " << min_2 << " " << min_3 << endl;
    return 0;
}
