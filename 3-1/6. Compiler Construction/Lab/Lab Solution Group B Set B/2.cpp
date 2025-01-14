#include <bits/stdc++.h>
using namespace std;

#define MAX_PRODUCT 500

#define pb push_back

/*
Input:
 A = A a B | A a | a
 B = B a | b | c
 EOF
*/

struct GRMR
{
    string NT;
    vector<string> PROD;
};

string get_next(int &i, string &line)
{
    string str;

    while (i < line.size() and line[i] != '|')
    {
        str.pb(line[i]);
        ++i;
    }
    ++i;

    return str;
}

void Replace(GRMR &replace, vector<string> PROD, int k)
{

    string alpha = replace.PROD[k].substr(1);
    replace.PROD.erase(replace.PROD.begin() + k);

    for (string P : PROD)
    {
        replace.PROD.insert(replace.PROD.begin() + k, P + alpha);
        ++k;
    }
}

void RemoveItem(GRMR eliminated[], GRMR &replacePROD, int &eliminated_no)
{
    vector<string> alpha, beta;

    for (string P : replacePROD.PROD)
    {
        if (P[0] == replacePROD.NT[0])
            alpha.pb(P.substr(1));
        else
            beta.pb(P);
    }

    if (alpha.size() == 0)
        return void();

    replacePROD.PROD.clear();

    for (string B : beta)
        replacePROD.PROD.pb(B + replacePROD.NT[0] + "'");

    eliminated_no += 1;
    eliminated[eliminated_no].NT = replacePROD.NT + "'";

    for (string A : alpha)
        eliminated[eliminated_no].PROD.pb(A + replacePROD.NT[0] + "'");
    eliminated[eliminated_no].PROD.pb("e");
}

int main()
{
    GRMR input[MAX_PRODUCT];
    int N = 0;

    string line;

    while (getline(cin, line))
    {
        string t;
        for (char c : line)
        {
            if (c != ' ')
                t.pb(c);
        }
        line = t;

        if (line == "EOF")
        {
            break;
        }

        input[N].NT = line[0];

        int i = 2;

        while (i < line.size())
        {
            input[N].PROD.pb(get_next(i, line));
        }

        N += 1;
    }

    GRMR eliminated[MAX_PRODUCT];
    int eliminated_no = 0;

    for (int i = 0; i < N; i++)
    {

        eliminated[eliminated_no] = input[i];

        for (int j = 0; j < eliminated_no; j++)
        {
            if (eliminated[j].NT.size() > 1)
            {
                continue;
            }
            for (int k = 0; k < eliminated[eliminated_no].PROD.size(); k++)
            {
                if (eliminated[eliminated_no].PROD[k][0] == eliminated[j].NT[0])
                {
                    Replace(eliminated[eliminated_no], eliminated[j].PROD, k);
                }
            }
        }

        RemoveItem(eliminated, eliminated[eliminated_no], eliminated_no);

        eliminated_no += 1;
    }

    for (int i = 0; i < eliminated_no; i++)
    {
        cout << eliminated[i].NT << " ->";
        for (int j = 0; j < eliminated[i].PROD.size(); j++)
        {
            if (j > 0)
                cout << " |";
            cout << " " << eliminated[i].PROD[j];
        }
        cout << eliminated_no << "\n";
    }

    return 0;
}