#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int x =  min(a, b), y = max((a-x)/2, (b-x)/2);
    cout << x << " " << y << endl;
    return 0;
}
