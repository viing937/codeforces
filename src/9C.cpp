#include <iostream>
using namespace std;

int lenint(int n)
{
    int cnt = 0;
    while ( n )
    {
        cnt += 1;
        n /= 10;
    }
    return cnt;
}

int highbit(int n)
{
    while ( n/10 )
        n /= 10;
    return n;
}

void cal(int n, int &result)
{
    if ( n == 0 )
    {
        result += 1;
        return;
    }
    int cnt = lenint(n), bit = highbit(n);
    if ( bit > 1 )
        result += 1<<cnt;
    else
    {
        result += 1<<(cnt-1);
        int t = 1;
        for ( int i = 1; i < cnt; ++i )
            t *= 10;
        cal(n%t, result);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int result = 0;
    cal(n, result);
    cout << result-1 << endl;
    return 0;
}
