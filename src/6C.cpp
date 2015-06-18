#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct Eater
{
    int ate;
    int wait;
    Eater()
    {
        ate=wait=0;
    }
};

int main()
{
    int n;
    struct Eater alice,bob;
    deque<int> chocs;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        int t;
        cin >> t;
        chocs.push_back(t);
    }
    while ( chocs.size() > 0 )
    {
        if ( alice.wait != 0 )
            alice.wait--;
        if ( bob.wait != 0 )
            bob.wait--;
        if ( alice.wait == 0 )
        {
            alice.wait = chocs[0];
            alice.ate++;
            chocs.pop_front();
        }
        if ( bob.wait == 0 )
        {
            if ( chocs.size() == 0 )
                break;
            else
            {
                bob.wait = chocs[chocs.size()-1];
                bob.ate++;
                chocs.pop_back();
            }
        }
    }
    cout << alice.ate << " " << bob.ate << endl;
    return 0;
}
