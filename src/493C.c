#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int binary(int l, int r, int target, int arr[])
{
    int middle = (l+r)>>1;
    if ( arr[middle] <= target && arr[middle+1] > target )
        return middle;
    else if ( arr[middle] > target )
        return binary(l, middle-1, target, arr);
    else
        return binary(middle+1, r, target, arr);
}

void cal(int *l, int *r, int first[], int n, int second[], int m, int d)
{
    int ll = n-binary(0, n+1, d, first),
        rr = m-binary(0, m+1, d, second);
    if ( ll < 0 || rr < 0 )
        return;
    if ( (ll-rr > *l-*r) || (ll-rr==*l-*r && ll>*l) )
    {
        *l = ll;
        *r = rr;
    }
    return;
}

int main()
{
    int i;
    int n, m;
    int first[200005] = {0}, second[200005] = {0};
    scanf("%d", &n);
    for ( i = 1; i <= n; i++ )
        scanf("%d", &first[i]);
    scanf("%d", &m);
    for ( i = 1; i <= m; i++ )
        scanf("%d", &second[i]);
    qsort(first, n+1, sizeof(first[0]), cmp);
    qsort(second, m+1, sizeof(second[0]), cmp);
    first[n+1] = 0x7fffffff;
    second[m+1] = 0x7fffffff;
    int l = n, r = m;
    for ( i = 1; i <= n; i++ )
        cal(&l, &r, first, n, second, m, first[i]);
    for ( i = 1; i <= m; i++ )
        cal(&l, &r, first, n, second, m, second[i]);
    printf("%d:%d\n", 2*n+l, 2*m+r);
    return 0;
}
