#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> board(8);
    for ( int i = 0; i < 8; ++i )
        cin >> board[i];
    int nearest_w = 15, nearest_b = 15;
    for ( int i = 0; i < 8; ++i )
    {
        for ( int j = 0; j < 8; ++j )
        {
            if ( board[j][i] == 'B' )
                break;
            if ( board[j][i] == 'W' )
            {
                nearest_w = min(nearest_w, j);
                break;
            }
        }
        for ( int j = 7; j >= 0; --j )
        {
            if ( board[j][i] == 'W' )
                break;
            if ( board[j][i] == 'B' )
            {
                nearest_b = min(nearest_b, 7-j);
                break;
            }
        }
    }
    if ( nearest_w <= nearest_b )
        cout << 'A' << '\n';
    else
        cout << 'B' << '\n';
    return 0;
}
