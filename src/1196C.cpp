#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MINP = -100000, MAXP = 100000;

int main()
{
    int q;
    cin >> q;
    for (int _ = 0 ; _ < q; _++)
    {
        pair<int, int> lb(MINP, MINP), rt(MAXP, MAXP);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y, f1, f2, f3, f4;
            cin >> x >> y >> f1 >> f2 >> f3 >> f4;
            if (!f1)
                lb.first = max(lb.first, x);
            if (!f2)
                rt.second = min(rt.second, y);
            if (!f3)
                rt.first = min(rt.first, x);
            if (!f4)
                lb.second = max(lb.second, y);
        }
        if (lb.first <= rt.first && lb.second <= rt.second)
            cout << 1 << " " << lb.first << " " << lb.second << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}