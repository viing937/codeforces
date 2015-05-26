#include <stdio.h>

int binary(int l, int r, int target, int arr[])
{
    if ( l <= r )
    {
        int mid = (l+r)/2;
        if ( arr[mid] <= target && arr[mid+1] > target )
            return mid;
        else if ( arr[mid] > target )
            return binary(l, mid-1, target, arr);
        else
            return binary(mid+1, r, target, arr);
    }
    return -1;
}

int main()
{
    int i;
    int n, d;
    int arr[100005];
    scanf("%d%d", &n, &d);
    for ( i = 0; i < n; i++ )
        scanf("%d", &arr[i]);
    arr[n] = 2147483647;
    long long ans = 0;
    for ( i = 0; i < n-2; i++ )
    {
        int index = binary(0, n, arr[i]+d, arr);
        if ( index > i+1 )
            ans += (long long)(index-i)*(index-i-1)/2;
    }
    printf("%lld\n", ans);
    return 0;
}
