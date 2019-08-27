#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

tuple<int, int, int> findmax(vector<int> &arr)
{
    int val = arr[0], left = 0, right = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] > val)
        {
            val = arr[i];
            left = right = i;
        }
        else if (arr[i] == val)
            right = i;
    }
    return make_tuple(val, left, right);
}

tuple<int, int, int> findmin(vector<int> &arr)
{
    int val = arr[0], left = 0, right = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] < val)
        {
            val = arr[i];
            left = right = i;
        }
        else if (arr[i] == val)
            right = i;
    }
    return make_tuple(val, left, right);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        string s;
        vector<int> hor(1, 0), ver(1, 0);
        cin >> s;
        for (char ch : s)
        {
            if (ch == 'W')
                ver.push_back(ver.back() + 1);
            else if (ch == 'S')
                ver.push_back(ver.back() - 1);
            else if (ch == 'A')
                hor.push_back(hor.back() - 1);
            else
                hor.push_back(hor.back() + 1);
        }

        auto [hormax, hormax_left, hormax_right] = findmax(hor);
        auto [hormin, hormin_left, hormin_right] = findmin(hor);

        auto [vermax, vermax_left, vermax_right] = findmax(ver);
        auto [vermin, vermin_left, vermin_right] = findmin(ver);

        long long rls = (long long)(hormax - hormin + 1) * (vermax - vermin + 1);
        if (vermax_left > vermin_right || vermin_left > vermax_right)
            if (vermax - vermin + 1 > 2)
                rls = min(rls, (long long)(hormax - hormin + 1) * (vermax - vermin));
        if (hormax_left > hormin_right || hormin_left > hormax_right)
            if (hormax - hormin + 1 > 2)
                rls = min(rls, (long long)(hormax - hormin) * (vermax - vermin + 1));
        cout << rls << endl;
    }
    return 0;
}