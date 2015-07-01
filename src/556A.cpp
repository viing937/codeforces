#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt_0 = count(s.begin(), s.end(), '0');
    int cnt_1 = count(s.begin(), s.end(), '1');
    cout << max(cnt_0, cnt_1)-min(cnt_0, cnt_1) << endl;
    return 0;
}
