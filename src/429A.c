#include <stdio.h>
#include <string.h>

void dfs(int node, int tree[], int cnt[], int init[], int goal[], int flag[])
{
    int father = tree[tree[node]];
    if ( father == 0 )
    {
        if ( init[node] != goal[node] )
        {
            flag[node] = 1;
            cnt[node] = 1;
        }
        else
            cnt[node] = 0;
    }
    else
    {
        if ( cnt[father] == -1 )
            dfs(father, tree, cnt, init, goal, flag);
        if ( (cnt[father]+init[node])%2 != goal[node]%2 )
        {
            flag[node] = 1;
            cnt[node] = cnt[father]+1;
        }
        else
        {
            cnt[node] = cnt[father];
        }
    }
    return;
}

int main()
{
    int i;
    int n;
    int init[100005], goal[100005];
    int tree[100005], cnt[100005];
    int flag[100005];
    memset(tree, 0, sizeof(tree));
    memset(flag, 0, sizeof(flag));
    memset(cnt, -1, sizeof(cnt));
    scanf("%d", &n);
    for ( i = 0; i < n-1; i++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if ( tree[u] != 0 || u == 1 )
            tree[v] = u;
        else
            tree[u] = v;
    }
    for ( i = 1; i <= n; i++ )
        scanf("%d", &init[i]);
    for ( i = 1; i <= n; i++ )
        scanf("%d", &goal[i]);
    for ( i = 1; i <= n; i++ )
        dfs(i, tree, cnt, init, goal, flag);
    int ans = 0;
    for ( i = 1; i <= n; i++ )
        ans += flag[i];
    printf("%d\n", ans);
    for ( i = 1; i <= n; i++ )
        if ( flag[i] )
            printf("%d\n", i);
    return 0;
}
