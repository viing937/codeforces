#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Cut
{
    char flag;
    int pos;
};

int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    set<int> hor, ver;
    hor.insert(0);
    hor.insert(w);
    ver.insert(0);
    ver.insert(h);
    vector<Cut> s;
    while ( n-- )
    {
        Cut tmp;
        cin >> tmp.flag >> tmp.pos;
        s.push_back(tmp);
        if ( tmp.flag == 'H' )
            ver.insert(tmp.pos);
        else
            hor.insert(tmp.pos);
    }
    int pre;
    int hormax = -1;
    pre = *hor.begin();
    for ( set<int>::iterator it = hor.begin(); it != hor.end(); it++ )
    {
        if ( *it-pre > hormax )
            hormax = *it-pre;
        pre = *it;
    }
    int vermax = -1;
    pre = *ver.begin();
    for ( set<int>::iterator it = ver.begin(); it != ver.end(); it++ )
    {
        if ( *it-pre > vermax )
            vermax = *it-pre;
        pre = *it;
    }
    vector<long long> ans;
    for ( int i = s.size()-1; i >= 0; i-- )
    {
        ans.push_back((long long)vermax*hormax);
        if ( s[i].flag == 'H' )
        {
            set<int>::iterator it = ver.find(s[i].pos);
            ver.erase(it--);
            int left = *(it++);
            int right = *it;
            if ( right-left > vermax )
                vermax = right-left;
        }
        else
        {
            set<int>::iterator it = hor.find(s[i].pos);
            hor.erase(it--);
            int left = *(it++);
            int right = *it;
            if ( right-left > hormax )
                hormax = right-left;
        }
    }
    for ( int i = ans.size()-1; i >= 0; i-- )
        cout << ans[i] << endl;
    return 0;
}
