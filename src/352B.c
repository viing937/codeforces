#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int a;
    int index;
};

int cmp(const void *a, const void *b)
{
    if ( (*(struct Node *)a).a == (*(struct Node *)b).a )
        return (*(struct Node *)a).index - (*(struct Node *)b).index;
    else
        return (*(struct Node *)a).a - (*(struct Node *)b).a;
}

int check(struct Node *node, int start, int end)
{
    int i;
    int diff;
    if ( end == start )
        return 0;
    diff = node[start+1].index - node[start].index;
    for ( i = start+2; i <= end; i++ )
        if ( node[i].index - node[i-1].index != diff )
            return -1;
    return diff;
}

int main()
{
    int i;
    int start, end;
    int t, tmp;
    int x[100005], p[100005];
    int n;
    struct Node node[100005];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
    {
        scanf("%d", &node[i].a);
        node[i].index = i;
    }
    qsort(node, n, sizeof(struct Node), cmp);
    t = start = end = 0;
    for ( i = 1; i < n; i++ )
    {
        if ( node[i].a == node[start].a )
            end++;
        else
        {
            tmp = check(node, start, end);
            if ( tmp >= 0 )
            {
                x[t] = node[start].a;
                p[t] = tmp;
                t++;
            }
            start = end = i;
        }
    }
    tmp = check(node, start, end);
    if ( tmp >= 0 )
    {
        x[t] = node[start].a;
        p[t] = tmp;
        t++;
    }
    printf("%d\n", t);
    for ( i = 0; i < t; i++ )
        printf("%d %d\n", x[i], p[i]);
    return 0;
}
