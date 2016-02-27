#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long t = 0;
    while ( (t%2 ? (t+1)/2*(t+2) : (t+2)/2*(t+1)) < n )
        t += 1;
    cout << n - (t%2 ? (t+1)/2*t : t/2*(t+1)) << endl;
    return 0;
}
