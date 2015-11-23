#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> x, y;
    while ( n-- )
    {
        int xx, yy;
        cin >> xx >> yy;
        x.insert(xx);
        y.insert(yy);
    }
    if ( x.size() != 2 || y.size() != 2 )
        cout << -1 << endl;
    else
    {
        int a = *next(x.begin(),1)-*x.begin();
        int b = *next(y.begin(),1)-*y.begin();
        cout << a*b << endl;
    }
    return 0;
}
