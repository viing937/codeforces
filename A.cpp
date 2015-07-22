#include <cstdio>
#include <vector>
#define MAXN 1000000
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<bool> mark(MAXN+5, false);
    for ( int i = 0; i < n; i++ )
    {
        int tmp;
        scanf("%d", &tmp);
        mark[tmp] = true;
    }
    if ( mark[1] )
        printf("-1\n");
    else
    {
        for ( int i = 1; i <= MAXN; i++ )
            if ( !mark[i] )
            {
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}
