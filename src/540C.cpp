#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, +1,  0,  0},
    dy[] = { 0,  0, -1, +1};

bool dfs(int x, int y, int xx, int yy, vector<string> &cells)
{
    if ( cells[x][y] == 'X' )
    {
        if ( x == xx && y == yy )
            return true;
        else
            return false;
    }
    cells[x][y] = 'X';
    bool result = false;
    int n = cells.size(), m = cells[0].size();
    for ( int i = 0; i < 4; ++i )
    {
        int nx = x+dx[i], ny = y+dy[i];
        if ( nx >= 0 && nx < n && ny >= 0 && ny < m )
            result |= dfs(x+dx[i], y+dy[i], xx, yy, cells);
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> cells(n);
    for ( int i = 0; i < n; ++i )
        cin >> cells[i];
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cells[r1-1][c1-1] = '.';
    if ( dfs(r1-1, c1-1, r2-1, c2-1, cells) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
