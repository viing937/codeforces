#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector< vector<int> > a(5001);
    ifstream in("input.txt");
    in >> n;
    for ( int i = 0; i < 2*n; i++ )
    {
        int tmp;
        in >> tmp;
        a[tmp].push_back(i+1);
    }
    in.close();
    ofstream out("output.txt");
    for ( int i = 1; i <= 5000; i++ )
    {
        if ( a[i].size()%2 != 0 )
        {
            out << -1 << "\n";
            out.close();
            return 0;
        }
    }
    for ( int i = 1; i <= 5000; i++ )
    {
        for ( int j = 0; j < (int)a[i].size(); j+=2 )
        {
            out << a[i][j] << " " << a[i][j+1] << "\n";
        }
    }
    out.close();
    return 0;
}
