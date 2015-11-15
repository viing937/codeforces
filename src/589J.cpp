#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int w, h;
    cin >> w >> h;
    vector<string> m(w);
    for ( int i = 0; i < w; ++i )
        cin >> m[i];
    int x, y, dir;
    int dx[] = {-1, 0, +1, 0},
        dy[] = {0, +1, 0, -1};
    for ( int i = 0; i < w; ++i )
    {
        for ( int j = 0; j < h; ++j )
        {
            if ( m[i][j] == '.' || m[i][j] == '*' )
                continue;
            x = i, y = j;
            if ( m[i][j] == 'U' ) dir = 0;
            if ( m[i][j] == 'R' ) dir = 1;
            if ( m[i][j] == 'D' ) dir = 2;
            if ( m[i][j] == 'L' ) dir = 3;
            break;
        }
    }
    int result = 1, cnt = 0;
    vector< vector<bool> > visited(w, vector<bool>(h, false));
    visited[x][y] = true;
    while ( true )
    {
        int tmp = 0;
        while ( x+dx[dir] >= 0 && x+dx[dir] < w &&
                y+dy[dir] >= 0 && y+dy[dir] < h &&
                m[x+dx[dir]][y+dy[dir]] != '*' )
        {
            x += dx[dir];
            y += dy[dir];
            if ( !visited[x][y] )
            {
                tmp += 1;
                visited[x][y] = true;
            }
        }
        if ( tmp == 0 )
        {
            cnt += 1;
            if ( cnt > 4 )
                break;
        }
        else
            cnt = 0;
        result += tmp;
        dir = (dir+1)%4;
    }
    cout << result << endl;
    return 0;
}
