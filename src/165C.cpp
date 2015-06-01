#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int k;
    char s[1000005];
    cin >> k >> s;
    if ( k == 0 )
    {
        long long ans = 0;
        long long cnt = 0;
        for ( int i = 0; i < (int)strlen(s); i++ )
        {
            if ( s[i] == '0' )
                cnt++;
            else
            {
                ans += cnt;
                if ( cnt >= 1 )
                    ans += cnt*(cnt-1)/2;
                cnt = 0;
            }
        }
        ans += cnt;
        if ( cnt >= 1 )
            ans += cnt*(cnt-1)/2;
        cout << ans << "\n";
        return 0;
    }
    int start = 0, end = -1;
    for ( int i = 0, cnt = 0; i < (int)strlen(s); i++ )
    {
        if ( s[i] == '1' )
            cnt++;
        if ( cnt >= k )
        {
            end = i;
            break;
        }
    }
    if ( end == -1 )
    {
        cout << 0 << "\n";
        return 0;
    }
    long long ans = 0;
    while ( s[end] != '\0' )
    {
        long long cntl = 1;
        while ( s[start] == '0' )
        {
            cntl++;
            start++;
        }
        start++;
        long long cntr = 1;
        while ( s[end+1] != '\0' && s[end+1] != '1' )
        {
            cntr++;
            end++;
        }
        end++;
        ans += cntl*cntr;
    }
    cout << ans << "\n";
    return 0;
}
