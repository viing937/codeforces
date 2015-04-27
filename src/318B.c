#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int len;
    long long ans = 0;
    char s[1000005];
    int cnt[1000005];
    scanf("%s", s);
    len = strlen(s);
    memset(cnt, 0, sizeof(cnt));
    for ( i = len-5; i >= 0; i-- )
    {
        if ( s[i] == 'm' && s[i+1] == 'e' && s[i+2] == 't' && s[i+3] == 'a' && s[i+4] == 'l' )
            cnt[i] = cnt[i+1]+1;
        else
            cnt[i] = cnt[i+1];
    }
    for ( i = 0; i < len-5; i++ )
    {
        if ( s[i] == 'h' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'v' && s[i+4] == 'y' )
            ans += cnt[i];
    }
    printf("%lld\n", ans);
    return 0;
}
