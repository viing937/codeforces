#include <iostream>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int indexA = 0, indexB = 0;
    while ( a[indexA] == '0' )
        indexA += 1;
    while ( b[indexB] == '0' )
        indexB += 1;
    if ( a.size()-indexA > b.size()-indexB )
        cout << '>' << endl;
    else if ( a.size()-indexA < b.size()-indexB )
        cout << '<' << endl;
    else
    {
        while ( indexA < (int)a.size() && a[indexA] == b[indexB] )
            indexA += 1, indexB += 1;
        if ( indexA == (int)a.size() )
            cout << '=' << endl;
        else if ( a[indexA] > b[indexB] )
            cout << '>' << endl;
        else
            cout << '<' << endl;
    }
    return 0;
}
