#include <stdio.h>

int count(int arr[], int n)
{
    int i;
    int result = 0, cnt = 0;
    for ( i = 1; i <= n; i++ )
    {
        if ( arr[i] )
            cnt++;
        else
            cnt = 0;
        result = result>cnt ? result : cnt;
    }
    return result;
}

int findmax(int arr[], int n)
{
    int i;
    int result = arr[0];
    for ( i = 1; i <= n; i++ )
        result = result>arr[i] ? result : arr[i];
    return result;
}

int main()
{
    int i, j;
    int n, m, q;
    int arr[505][505];
    int rowmax[505];
    scanf("%d%d%d", &n, &m, &q);
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
            scanf("%d", &arr[i][j]);
        rowmax[i] = count(arr[i], m);
    }
    int ans = findmax(rowmax, n);
    while ( q-- )
    {
        scanf("%d%d", &i, &j);
        if ( arr[i][j] == 0 )
        {
            arr[i][j] = 1;
            rowmax[i] = count(arr[i], m);
            ans = rowmax[i]>ans ? rowmax[i] : ans;
        }
        else
        {
            arr[i][j] = 0;
            rowmax[i] = count(arr[i], m);
            ans = findmax(rowmax, n);
        }
        printf("%d\n", ans);
    }
    return 0;
}
