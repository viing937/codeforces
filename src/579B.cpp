#include <cstdio>
#include <set>
#include <map>
using namespace std;

struct Team
{
    int strength;
    int a;
    int b;
    bool operator <(const Team &t) const
    {
        return strength < t.strength;
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    set<Team> a;
    for ( int i = 2; i <= 2*n; ++i )
    {
        for ( int j = 1; j < i; ++j )
        {
            Team tmp;
            scanf("%d", &tmp.strength);
            tmp.a = i, tmp.b = j;
            a.insert(tmp);
        }
    }
    map<int, int> result;
    for ( auto it = a.rbegin(); it != a.rend(); ++it )
    {
        if ( result.find(it->a) == result.end() && result.find(it->b) == result.end() )
        {
            result[it->a] = it->b;
            result[it->b] = it->a;
        }
    }
    for ( int i = 1; i < 2*n; ++i )
        printf("%d ", result[i]);
    printf("%d\n", result[2*n]);
    return 0;
}
