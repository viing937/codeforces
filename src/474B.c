#include <stdio.h>
int binary_search(int a[], int left, int right, int target)
{
    if(left==right)
        return left;
    int middle = (left+right)/2;
    if(a[middle]>=target)
        return binary_search(a, left, middle, target);
    else
        return binary_search(a, middle+1, right, target);
}
int main()
{
    int i;
    int n, m, q;
    int a[100005] = {0};
    scanf("%d",&n);
    for(i = 1; i <= n; i++ )
    {
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++ )
    {
        scanf("%d", &q);
        printf("%d\n", binary_search(a, 1, n, q));
    }
    return 0;
}
