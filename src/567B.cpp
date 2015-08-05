#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1000000
using namespace std;

int main()
{
    int n;
    vector<int> state(MAXN+5, 0);
    cin >> n;
    vector<char> flag(n);
    vector<int> reg(n);
    int ans = 0, cnt = 0, tmp = 0;
    for ( int i = 0; i < n; ++i )
    {
        cin >> flag[i] >> reg[i];
        if ( flag[i] == '+' )
            state[reg[i]] = 1;
        else if ( flag[i] == '-' )
        {
            if ( state[reg[i]] == 1 )
                state[reg[i]] = 0;
            else
                tmp += 1;
        }
    }
    for ( unsigned int i = 0; i < state.size(); ++i )
        state[i] = 0;
    ans = tmp;
    for ( int i = 0; i < n; ++i )
    {
        if ( flag[i] == '+' )
        {
            cnt += 1;
            state[reg[i]] = 1;
        }
        else if ( state[reg[i]] == 1 )
        {
            cnt -= 1;
            state[reg[i]] = 0;
        }
        else
            tmp -= 1;
        ans = max(ans, cnt+tmp);
    }
    cout << ans << endl;
    return 0;
}
