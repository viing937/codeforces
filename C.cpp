#include <iostream>
using namespace std;

int main()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    int cnt = 0;
    for ( int i = 1; i < n; i++ )
    {
        if ( s[i] == '.' && s[i-1] == '.' )
            cnt += 1;
    }
    for ( int i = 0; i < m; i++ )
    {
        int x;
        char c;
        cin >> x >> c;
        if ( c != '.' && s[x-1] == '.' )
        {
            int cnt_left = 0, cnt_right = 0;
            for ( int j = x-2; j >= 0 && s[j] == '.'; --j )
                cnt_left += 1;
            for ( int j = x; j < n && s[j] == '.'; ++j )
                cnt_right += 1;
            if ( (cnt_left == 0 && cnt_right >= 1) || (cnt_left >= 1 && cnt_right == 0) )
                cnt -= 1;
            else if ( cnt_left >= 1 && cnt_right >= 1 )
                cnt -= 2;
            s[x-1] = c;
        }
        else if ( c == '.' && s[x-1] != '.' )
        {
            int cnt_left = 0, cnt_right = 0;
            for ( int j = x-2; j >= 0 && s[j] == '.'; --j )
                cnt_left += 1;
            for ( int j = x; j < n && s[j] == '.'; ++j )
                cnt_right += 1;
            if ( (cnt_left == 0 && cnt_right >= 1) || (cnt_left >= 1 && cnt_right == 0) )
                cnt += 1;
            else if ( cnt_left >= 1 && cnt_right >= 1 )
                cnt += 2;
            s[x-1] = c;
        }
        cout << cnt << endl;
    }
    return 0;
}
