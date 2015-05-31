#include <stdio.h>

int main()
{
    int i;
    int ans, disl, disr;
    int n, p;
    char s[100005];
    scanf("%d%d%s", &n, &p, s);
    if ( p > n/2 )
        p = n-p+1;
    ans = disl = disr = 0;
    for ( i = 0; p-i-1 >= 0; i++ )
    {
        if ( s[p-i-1] != s[n-p+i] )
        {
            int dis = (s[p-i-1]-s[n-p+i]+26)%26;
            ans += dis>26-dis ? 26-dis : dis;
            disl = i;
        }
    }
    for ( i = 1; p+i-1 < n/2; i++ )
    {
        if ( s[p+i-1] != s[n-p-i] )
        {
            int dis = (s[p+i-1]-s[n-p-i]+26)%26;
            ans += dis>26-dis ? 26-dis : dis;
            disr = i;
        }
    }
    ans += disl + disr;
    ans += disl<disr ? disl : disr;
    printf("%d\n", ans);
    return 0;
}
