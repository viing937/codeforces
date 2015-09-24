#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

struct Friend
{
    long long m;
    long long s;
    bool operator <(const Friend &f) const
    {
        if ( m != f.m )
            return m < f.m;
        else
            return s > f.s;
    }
};

int main()
{
    int n;
    long long d;
    scanf("%d%lld", &n, &d);
    multiset<Friend> s;
    for ( int i = 0; i < n; ++i )
    {
        Friend tmp;
        scanf("%lld%lld", &tmp.m, &tmp.s);
        s.insert(tmp);
    }
    auto start = s.begin(), end = s.begin();
    long long sum = 0, result = 0;
    while ( end != s.end() )
    {
        sum += end->s;
        while ( end->m - start->m >= d )
            sum -= (start++)->s;
        result = max(result, sum);
        ++end;
    }
    printf("%lld\n", result);
    return 0;
}
