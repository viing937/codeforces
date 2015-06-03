#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct Candy
{
    int h;
    int m;
};

bool operator < (const Candy &a, const Candy &b)
{
    if ( a.m == b.m )
        return a.h < b.h;
    else
        return b.m < a.m;
}

int find(int &x, multiset<Candy> &s)
{
    for ( multiset<Candy>::iterator it=s.begin(); it!=s.end(); it++)
    {
        if ( (*it).h <= x )
        {
            x += (*it).m;
            s.erase(it);
            return 1;
        }
    }
    return 0;
}

int cal(int x, multiset<Candy> first, multiset<Candy> second)
{
    int result = 0;
    while ( 1 )
    {
        if ( first.empty() )
            break;
        if ( find(x, first) )
            result += 1;
        else
            break;
        if ( second.empty() )
            break;
        if ( find(x, second) )
            result += 1;
        else
            break;
    }
    return result;
}

int main()
{
    int n, x;
    cin >> n >> x;
    multiset<Candy> typea, typeb;
    for ( int i = 0; i < n; i++ )
    {
        int t;
        Candy c;
        cin >> t >> c.h >> c.m;
        if ( t == 0 )
            typea.insert(c);
        else
            typeb.insert(c);
    }
    cout << max(cal(x, typea, typeb),cal(x,typeb, typea)) << endl;
    return 0;
}
