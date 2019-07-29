#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++)
    {
        int b, w;
        cin >> b >> w;
        if (max(b, w) > 3 * min(b, w) + 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            if (b > w)
            {
                for (int i = 0; i < w + 1 && i < b; i++)
                    cout << 2 << " " << i * 2 + 1 << endl;
                for (int i = 0; i < w && i + w + 1 < b; i++)
                    cout << 1 << " " << i * 2 + 2 << endl;
                for (int i = 0; i < w && i + 2 * w + 1 < b; i++)
                    cout << 3 << " " << i * 2 + 2 << endl;
                for (int i = 0; i < w; i++)
                    cout << 2 << " " << i * 2 + 2 << endl;
            }
            else
            {
                for (int i = 0; i < b; i++)
                    cout << 3 << " " << i * 2 + 2 << endl;
                for (int i = 0; i < b + 1 && i < w; i++)
                    cout << 3 << " " << i * 2 + 1 << endl;
                for (int i = 0; i < b && i + b + 1 < w; i++)
                    cout << 2 << " " << i * 2 + 2 << endl;
                for (int i = 0; i < b && i + 2 * b + 1 < w; i++)
                    cout << 4 << " " << i * 2 + 2 << endl;
            }
        }
    }
    return 0;
}