#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int num, prevNum;
    int count = 1, result = 1;
    scanf("%d", &prevNum);
    for ( int i = 1; i < n; ++i )
    {
        scanf("%d", &num);
        if ( num >= prevNum )
            count += 1;
        else
            count = 1;
        result = max(result, count);
        prevNum = num;
    }
    printf("%d\n", result);
    return 0;
}
