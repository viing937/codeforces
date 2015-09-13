#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Vertex
{
    int k;
    int degree;
    int s;
};

int main()
{
    int n;
    cin >> n;
    vector<Vertex> vertexs(n);
    stack<Vertex> leaves;
    for ( int i = 0; i < n; ++i )
    {
        vertexs[i].k = i;
        cin >> vertexs[i].degree >> vertexs[i].s;
        if ( vertexs[i].degree == 1 )
            leaves.push(vertexs[i]);
    }
    vector<int> src, des;
    while ( !leaves.empty() )
    {
        Vertex vertex = leaves.top();
        leaves.pop();
        if ( vertexs[vertex.s].degree == 0 || vertexs[vertex.k].degree == 0 )
            continue;
        src.push_back(vertex.k), des.push_back(vertex.s);
        vertexs[vertex.s].degree -= 1;
        vertexs[vertex.s].s ^= vertexs[vertex.k].k;
        vertexs[vertex.k].degree -= 1;
        vertexs[vertex.k].s ^= vertexs[vertex.s].k;
        if ( vertexs[vertex.s].degree == 1 )
            leaves.push(vertexs[vertex.s]);
    }
    cout << src.size() << "\n";
    for ( unsigned int i = 0; i < src.size(); ++i )
        cout << src[i] << " " << des[i] << "\n";
    return 0;
}
