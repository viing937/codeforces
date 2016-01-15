#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

class NFA
{
public:
    int n;
    std::vector<char> charactor;
    std::vector< std::vector< std::vector<int> > > nfa_trans;
    std::vector<int> acc;

    NFA(const char *file)
    {
        std::ifstream in(file);
        std::string line;
        std::string::size_type sz;

        getline(in, line);
        n = stoi(line, &sz);
        for ( auto i = sz; i < line.size(); ++i )
            if ( line[i] != ',' )
                charactor.push_back(line[i]);

        nfa_trans = std::vector< std::vector< std::vector<int> > >(n, std::vector< std::vector<int> >(charactor.size()));

        for ( int i = 0; i < n; ++i )
        {
            getline(in, line);
            for ( int j = 0; j < (int)charactor.size(); ++j )
            {
                if ( line[0] == 'v' )
                {
                    if ( line.size() > 4 ) line = line.substr(5);
                    continue;
                }
                while ( line.size() && isdigit(line[0]) )
                {
                    nfa_trans[i][j].push_back(stoi(line, &sz));
                    if ( sz >= line.size() ) break;
                    else if ( line[sz] == ';' ) {line = line.substr(sz+1); break;}
                    else line = line.substr(sz+1);
                }
            }
        }

        getline(in, line);
        acc.push_back(stoi(line, &sz));
        while ( sz < line.size() )
        {
            line = line.substr(sz+1);
            acc.push_back(stoi(line, &sz));
        }
    }
    void show()
    {
        std::cout << n;
        for ( char ch : charactor )
            std::cout << ',' << ch;
        std::cout << '\n';

        for ( int i = 0; i < n; ++i )
        {
            for ( int j = 0; j < (int)charactor.size(); ++j )
            {
                if ( j != 0 ) std::cout << ';';
                if ( nfa_trans[i][j].size() == 0 )
                    std::cout << "void";
                else
                {
                    for ( int k = 0; k < (int)(nfa_trans[i][j].size()); ++k )
                    {
                        if ( k != 0 ) std::cout << ',';
                        std::cout << nfa_trans[i][j][k];
                    }
                }
            }
            std::cout << '\n';
        }

        for ( int i = 0; i < (int)acc.size(); ++i )
        {
            if ( i == 0 )
                std::cout << acc[i];
            else
                std::cout << ',' << acc[i];
        }
        std::cout << '\n';
    }
    std::vector<int> closure(const std::vector<int> &T)
    {
        std::vector<bool> visited(n, false);
        std::stack<int> s;
        for ( int t : T )
            s.push(t);

        int _ch = charactor.size()-1;
        while ( !s.empty() )
        {
            int cur = s.top();
            s.pop();
            visited[cur] = true;
            for ( int i = 0; i < (int)(nfa_trans[cur][_ch].size()); ++i )
            {
                if ( !visited[nfa_trans[cur][_ch][i]] )
                    s.push(nfa_trans[cur][_ch][i]);
            }
        }
        std::vector<int> TT;
        for ( int i = 0; i < n; ++i )
            if ( visited[i] )
                TT.push_back(i);
        return TT;
    }
};

class DFA
{
public:
    int n;
    std::vector<char> charactor;
    std::vector< std::vector<int> > dfa_trans;
    std::vector<int> acc;

    DFA(NFA nfa)
    {
        charactor = nfa.charactor;
        charactor.pop_back();

        std::vector< std::vector<int> > states;
        states.push_back(nfa.closure(std::vector<int>(1, 0)));
        dfa_trans.push_back(std::vector<int>(charactor.size()));

        for ( int i = 0; i < (int)states.size(); ++i )
        {
            for ( int j = 0; j < (int)nfa.charactor.size()-1; ++j )
            {
                std::vector<int> new_state;
                for ( auto s : states[i] )
                    for ( auto t : nfa.nfa_trans[s][j] )
                        new_state.push_back(t);
                sort(new_state.begin(), new_state.end());
                new_state.erase(std::unique(new_state.begin(), new_state.end()), new_state.end());
                new_state = nfa.closure(new_state);

                auto tmpIt = find(states.begin(), states.end(), new_state);
                if ( tmpIt == states.end() )
                {
                    states.push_back(new_state);
                    dfa_trans.push_back(std::vector<int>(charactor.size()));
                    dfa_trans[i][j] = states.size()-1;
                }
                else
                    dfa_trans[i][j] = tmpIt-states.begin();
            }
        }

        n = dfa_trans.size();
        for ( int i = 0; i < n; ++i )
        {
            for ( int acc_s : nfa.acc )
            {
                if ( find(states[i].begin(), states[i].end(), acc_s) != states[i].end() )
                {
                    acc.push_back(i);
                    break;
                }
            }
        }
    }
    void show()
    {
        std::cout << n;
        for ( auto ch : charactor )
            std::cout << ',' << ch;
        std::cout << '\n';

        for ( int i = 0; i < n; ++i )
        {
            for ( int j = 0; j < (int)charactor.size(); ++j )
            {
                if ( j == 0 )
                    std::cout << dfa_trans[i][j];
                else
                    std::cout << ',' << dfa_trans[i][j];
            }
            std::cout << '\n';
        }

        for ( int i = 0; i < (int)acc.size(); ++i )
        {
            if ( i == 0 )
                std::cout << acc[i];
            else
                std::cout << ',' << acc[i];
        }
        std::cout << '\n';
    }
};

int main()
{
    NFA nfa("nfa.txt");
    //nfa.show();
    DFA dfa(nfa);
    dfa.show();
    return 0;
}
