#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int binary_search(int left, int right, int a[], long long target)
{
    if ( left > right )
        return -1;
    int middle = (left+right)/2;
    if ( a[middle] == target )
        return middle;
    else if ( a[middle] > target )
        return binary_search(left, middle-1, a, target);
    else
        return binary_search(middle+1, right, a, target);
}

int main()
{
    int i, t, cnt, ans = 0;
    long long tmp;
    int n, k;
    int a[100005], mark[100005];
    memset(mark, 0, sizeof(mark));
    scanf("%d%d", &n, &k);
    if ( k == 1 )
    {
        printf("%d\n", n);
        return 0;
    }
    for ( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for ( i = 0; i < n; i++ )
    {
        if ( mark[i] )
            continue;
        cnt = 1;
        tmp = (long long)a[i]*k;
        t = binary_search(0, n-1, a, tmp);
        while ( t >= 0 )
        {
            cnt += 1;
            mark[t] = 1;
            tmp *= k;
            t = binary_search(0, n-1, a, tmp);
        }
        ans += (cnt+1)/2;
    }
    printf("%d\n", ans);
    return 0;
}
