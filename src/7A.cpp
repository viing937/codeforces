#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> board(8);
    for ( int i = 0; i < 8; ++i )
        cin >> board[i];
    vector<int> row(8), col(8);
    for ( int i = 0; i < 8; ++i )
    {
        for ( int j = 0; j < 8; ++j )
        {
            if ( board[i][j] == 'W' )
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    int result = 16-count(row.begin(), row.end(), 1)-count(col.begin(), col.end(), 1);
    if ( result == 16 )
        cout << result/2 << endl;
    else
        cout << result << endl;
    return 0;
}
