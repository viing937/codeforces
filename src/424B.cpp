#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;

struct Point
{
    double r;
    int pop;
};

bool operator < (const Point &a, const Point &b)
{
    if ( a.r == b.r )
        return a.pop < b.pop;
    else
        return a.r < b.r;
}

int main()
{
    int n, s;
    cin >> n >> s;
    multiset<Point> point;
    for ( int i = 0; i < n; i++ )
    {
        int x, y, k;
        cin >> x >> y >> k;
        Point p;
        p.r = sqrt(x*x+y*y);
        p.pop = k;
        point.insert(p);
    }
    for ( multiset<Point>::iterator it = point.begin(); it != point.end(); it++ )
    {
        s += (*it).pop;
        if ( s >= 1000000 )
        {
            cout << setiosflags(ios::fixed) << setprecision(10) << (*it).r << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
