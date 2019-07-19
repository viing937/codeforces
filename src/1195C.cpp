#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> h1(n), h2(n);
    for (int i = 0; i < n; i++)
        cin >> h1[i];
    for (int i = 0; i < n; i++)
        cin >> h2[i];
    long long maxh1 = h1[0], maxh2 = h2[0];
    for (int i = 1; i < n; i++)
    {
        long long tmph1 = max(maxh1, maxh2 + h1[i]);
        long long tmph2 = max(maxh2, maxh1 + h2[i]);
        maxh1 = tmph1;
        maxh2 = tmph2;
    }
    cout << max(maxh1, maxh2) << endl;
    return 0;
}