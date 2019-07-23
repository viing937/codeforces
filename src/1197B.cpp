#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        a.emplace_back(ai, i);
    }
    sort(a.begin(), a.end());
    int left = a.rbegin()->second - 1;
    int right = a.rbegin()->second + 1;
    a.pop_back();
    for (auto it = a.rbegin(); it != a.rend(); ++it)
    {
        if (left == it->second)
            left -= 1;
        else if (right == it->second)
            right += 1;
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}