#include <stdio.h>

int cal(double v, int k)
{
    int cnt = 0;
    while ( v >= 1 )
    {
        cnt += (int)v;
        v /= k;
    }
    return cnt;
}

int binary_search(int l, int r, int n, int k)
{
    int middle = (l+r)/2;
    if ( cal(middle, k) >= n )
    {
        if ( cal(middle-1, k) < n )
            return middle;
        else
            return binary_search(l, middle, n, k);
    }
    else
    {
        if ( cal(middle+1, k) >= n )
            return middle+1;
        else
            return binary_search(middle, r, n, k);
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", binary_search(1, n, n, k));
    return 0;
}
