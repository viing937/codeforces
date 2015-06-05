#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char s[100005];
    int cnt = 0, cnt1 = 0, cnt2 = 0;
    scanf("%s", s);
    for ( i = 0; i < strlen(s);)
    {
        if ( (s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='A') || (s[i]=='B'&&s[i+1]=='A'&&s[i+2]=='B') )
        {
            cnt += 1;
            i += 3;
        }
        else if ( s[i]=='A'&&s[i+1]=='B' )
        {
            cnt1 += 1;
            i += 2;
        }
        else if ( s[i]=='B'&&s[i+1]=='A' )
        {
            cnt2 += 1;
            i += 2;
        }
        else
            i += 1;
    }
    if ( cnt>=2 || (cnt&&cnt1) || (cnt&&cnt2) || (cnt1&&cnt2) )
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
