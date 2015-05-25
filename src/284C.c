#include <stdio.h>

int main()
{
    int n;
    int num = 1;
    double sum = 0;
    int arr[200005] = {0}, add[200005] = {0};
    scanf("%d", &n);
    while ( n-- )
    {
        int t;
        scanf("%d", &t);
        if ( t == 1 )
        {
            int a, x;
            scanf("%d%d", &a, &x);
            add[a-1] += x;
            sum += a*x;
        }
        else if ( t == 2 )
        {
            scanf("%d", &arr[num]);
            sum += arr[num++];
        }
        else
        {
            num--;
            sum -= arr[num]+add[num];
            add[num-1] += add[num];
            add[num] = 0;
        }
        printf("%lf\n", sum/num);
    }
    return 0;
}
