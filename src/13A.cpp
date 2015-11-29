#include <iostream>
using namespace std;

int cal(int x, int base)
{
    int result = 0;
    while ( x )
    {
        result += x%base;
        x /= base;
    }
    return result;
}

int main()
{
    int A;
    cin >> A;
    int numerator = 0, denominator = A-2;
    for ( int i = 2; i < A; ++i )
        numerator += cal(A, i);
    for ( int i = 2; i < A; ++i )
    {
        while ( numerator%i == 0 && denominator%i == 0 )
        {
            numerator /= i;
            denominator /= i;
        }
    }
    cout << numerator << '/' << denominator << endl;
    return 0;
}
