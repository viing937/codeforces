#include <iostream>
using namespace std;

bool test(int a1, int b1, int a2, int b2, int a3, int b3)
{
    if ( a2+a3 <= a1 && b2 <= b1 && b3 <= b1 )
        return true;
    else if ( b2+b3 <= b1 && a2 <= a1 && a3 <= a1 )
        return true;
    else
        return false;
}

int main()
{
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    if ( test(a1, b1, a2, b2, a3, b3) || 
         test(a1, b1, b2, a2, a3, b3) ||
         test(a1, b1, a2, b2, b3, a3) ||
         test(a1, b1, b2, a2, b3, a3) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
