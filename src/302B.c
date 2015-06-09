#include <stdio.h>

int binary(int l, int r, int target, int arr[])
{
    int middle = (l+r)>>1;
    if ( arr[middle]>=target && arr[middle-1]<target )
        return middle;
    else if ( arr[middle] > target )
        return binary(l, middle-1, target, arr);
    else
        return binary(middle+1, r, target, arr);
}

int main()
{
    int i;
    int n, m;
    int songs[100005] = {0};
    scanf("%d%d", &n, &m);
    for ( i = 1; i <= n; i++ )
    {
        int c, t;
        scanf("%d%d", &c, &t);
        songs[i] = songs[i-1]+c*t;
    }
    for ( i = 1; i <= m; i++ )
    {
        int v;
        scanf("%d", &v);
        printf("%d\n", binary(1,n,v,songs));
    }
    return 0;
}
