#include <cstdio>
using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if ( a < b )
    {
        printf("-1\n");
        return 0;
    }
    double result = (a+b)/2.0;
    result /= (int)(result/b);
    printf("%.10lf\n", result);
    return 0;
}
