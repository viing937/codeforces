#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long k = (sqrt(1+24*n)-1)/6;
    cout << (k+n%3)/3 << endl;
    return 0;
}
