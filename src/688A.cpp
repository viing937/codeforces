#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int ans = 0, cnt = 0;
    for (int i = 0; i < d; ++i)
    {
        string s;
        cin >> s;
        if (find(s.begin(), s.end(), '0') == s.end())
            cnt = 0;
        else
            cnt += 1;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
