#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    int index;
};

int cmp(const void *a, const void *b)
{
    if ( (*((struct Node*)a)).num == (*((struct Node*)b)).num )
        return (*((struct Node*)a)).index - (*((struct Node*)b)).index;
    else
        return (*((struct Node*)a)).num - (*((struct Node*)b)).num;
}

int main()
{
    int i;
    int n;
    int a[300005];
    struct Node li[300005];
    scanf("%d",&n);
    for ( i = 0; i < n; i++ )
    {
        scanf("%d",&a[i]);
        li[i].num = a[i];
        li[i].index = i;
    }
    qsort(li,n,sizeof(struct Node),cmp);
    for ( i = 0; i < n; i++ )
    {
        if ( i >= 1 )
            li[i].num = li[i].num>=li[i-1].num+1 ? li[i].num: li[i-1].num+1;
        a[li[i].index] = li[i].num;
    }
    printf("%d",a[0]);
    for ( i = 1; i < n; i++ )
        printf(" %d",a[i]);
    printf("\n");
    return 0;
}
