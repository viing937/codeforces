#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int result = 0, cnt = 0;
    bool start = false;
    while ( n-- )
    {
        int a;
        scanf("%d", &a);
        if ( a )
        {
            result += 1;
            if ( cnt == 1 && start )
                result += 1;
            cnt = 0;
            start = true;
        }
        else
            cnt += 1;
    }
    printf("%d\n", result);
    return 0;
}
