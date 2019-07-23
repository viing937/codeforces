#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int D = 5000;
const int N = 2 * D + 9;

void add(vector<int> &c, int x, int y)
{
    for (int i = x; i < c.size(); i |= i + 1)
    {
        c[i] += y;
    }
}

int get(vector<int> &c, int x)
{
    int rls = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
    {
        rls += c[i];
    }
    return rls;
}

int get(vector<int> &c, int l, int r)
{
    return get(c, r) - get(c, l - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> hs(N), vs(N);
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += D, y1 += D, x2 += D, y2 += D;
        if (x1 == x2)
            vs[x1].emplace_back(min(y1, y2), max(y1, y2));
        else
            hs[y1].emplace_back(min(x1, x2), max(x1, x2));
    }

    long long rls = 0;
    for (int y1 = 0; y1 < N; y1++)
    {
        for (const auto &[l, r] : hs[y1])
        {
            vector<int> c(N);
            vector<vector<int>> d(N);

            for (int x = l; x <= r; x++)
            {
                for (const auto &[down, up] : vs[x])
                {
                    if (down <= y1 && up > y1)
                    {
                        add(c, x, 1);
                        d[up].push_back(x);
                    }
                }
            }
            for (int y2 = y1 + 1; y2 < N; y2++)
            {
                for (const auto &[x1, x2] : hs[y2])
                {
                    int cnt = get(c, x1, x2);
                    rls += cnt * (cnt - 1) / 2;
                }
                for (int x : d[y2])
                {
                    add(c, x, -1);
                }
            }
        }
    }
    cout << rls << endl;
    return 0;
}