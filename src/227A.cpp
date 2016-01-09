#include <iostream>
using namespace std;

int main()
{
    long long ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    cx -= bx; cy -= by;
    bx -= ax; by -= ay;
    long long t = bx*cy-by*cx;
    if ( t > 0 )
        cout << "LEFT" << '\n';
    else if ( t < 0 )
        cout << "RIGHT" << '\n';
    else
        cout << "TOWARDS" << '\n';
    return 0;
}
