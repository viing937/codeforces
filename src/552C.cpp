#include <iostream>
#include <vector>
using namespace std;

bool cheak(int w, int m)
{
    vector<int> num;
    while ( m )
    {
        num.push_back(m%w);
        m /= w;
    }
    int carry = 0;
    for ( unsigned int i = 0; i < num.size(); ++i )
    {
        num[i] += carry;
        if ( num[i]%w == 0 || num[i]%w == 1 )
        {
            carry = num[i]/w;
            num[i] %= w;
        }
        else if ( num[i] == w-1 )
        {
            carry = (num[i]+1)/w;
            num[i] = (num[i]+1)%w;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    int w, m;
    cin >> w >> m;
    if ( cheak(w, m) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
