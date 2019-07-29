#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> idxs;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            if (a % 2)
                idxs.push_back(i);
        }
        int cnt = idxs.size();
        if (cnt < k || (cnt ^ k) & 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++)
                cout << idxs[i] << " ";
            cout << n << endl;
        }
    }
    return 0;
}