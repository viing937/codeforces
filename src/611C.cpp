#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> sl(h);
    for ( int i = 0; i < h; ++i )
        cin >> sl[i];
    vector< vector<int> > hor(h+1, vector<int>(w+1, 0)), ver(h+1, vector<int>(w+1, 0));
    for ( int i = 0; i < h; ++i )
    {
        for ( int j = 0; j < w; ++j )
        {
            hor[i+1][j+1] = hor[i+1][j]+hor[i][j+1]-hor[i][j];
            ver[i+1][j+1] = ver[i+1][j]+ver[i][j+1]-ver[i][j];
            if ( sl[i][j] != '.' ) continue;
            if ( i != h-1 && sl[i+1][j] == '.' ) hor[i+1][j+1]+=1;
            if ( j != w-1 && sl[i][j+1] == '.' ) ver[i+1][j+1]+=1;
        }
    }

    int q;
    cin >> q;
    while ( q-- )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 -= 1, y1 -= 1;
        int ans = 0;
        ans += hor[x2-1][y2]-hor[x1][y2]-hor[x2-1][y1]+hor[x1][y1];
        ans += ver[x2][y2-1]-ver[x1][y2-1]-ver[x2][y1]+ver[x1][y1];
        cout << ans << '\n';
    }
    return 0;
}
