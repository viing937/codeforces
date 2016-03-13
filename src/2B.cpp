#include <iostream>
#include <vector>
using namespace std;

int cal(vector< vector<int> > a, int t, vector<char> &seq)
{
    int n = a.size();
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < n; ++j )
        {
            int k = a[i][j];
            a[i][j] = 0;
            while ( k && k%t == 0 )
            {
                a[i][j] += 1;
                k /= t;
            }
        }
    }

    vector< vector<int> > acc(a);
    for ( int i = 1; i < n; ++i )
        acc[0][i] += acc[0][i-1];
    for ( int i = 1; i < n; ++i )
    {
        acc[i][0] += acc[i-1][0];
        for ( int j = 1; j < n; ++j )
            acc[i][j] += min(acc[i-1][j], acc[i][j-1]);
    }

    int cur_x = n-1, cur_y = n-1, idx = n*2-2;
    while ( idx )
    {
        if ( cur_x > 0 && acc[cur_x][cur_y] == acc[cur_x-1][cur_y]+a[cur_x][cur_y] )
        {
            seq[--idx] = 'D';
            cur_x -= 1;
        }
        else
        {
            seq[--idx] = 'R';
            cur_y -= 1;
        }
    }
    return acc[n-1][n-1];
}

void display(const vector<char> &s)
{
    for ( int i = 0; i < (int)s.size(); ++i )
        cout << s[i];
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > a(n, vector<int>(n));
    bool flag = false;
    int z_x, z_y;

    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < n; ++j )
        {
            cin >> a[i][j];
            if ( !a[i][j] )
            {
                flag = true;
                z_x = i, z_y = j;
            }
        }
    }

    vector<char> seq1(n*2-2), seq2(n*2-2);
    int cnt1 = cal(a, 2, seq1), cnt2 = cal(a, 5, seq2);
    if ( flag && cnt1 > 1 && cnt2 > 1 )
    {
        vector<char> seq;
        for ( int i = 0; i < z_x; ++i )
            seq.push_back('D');
        for ( int i = 0; i < z_y; ++i )
            seq.push_back('R');
        for ( int i = z_x+1; i < n; ++i )
            seq.push_back('D');
        for ( int i = z_y+1; i < n; ++i )
            seq.push_back('D');
        cout << 1 << '\n';
        display(seq);
    }
    else if ( cnt1 < cnt2 )
    {
        cout << cnt1 << '\n';
        display(seq1);
    }
    else
    {
        cout << cnt2 << '\n';
        display(seq2);
    }
    return 0;
}
