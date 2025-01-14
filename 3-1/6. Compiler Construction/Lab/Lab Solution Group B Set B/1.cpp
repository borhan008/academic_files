#include <bits/stdc++.h>
using namespace std;

bool possible;
int state;

/*

abcba
bcbcab

*/

// In C state
void stateC()
{
    state = 1;
}

// In B state
void stateCtoB()
{
    state = 2;
}
// In B state
void stateBtoA()
{
    state = 3;
    possible = true;
}
// state : 0
void state0()
{
    state = 0;
}
int main()
{

    while (true)
    {
        cout << "Enter a string: ";
        string s;
        cin >> s;

        if (s == "EOF")
            return 0;

        int len = s.length();
        possible = false;

        int i = 0;
        state = 0;
        /*
            State 0 : No substring is found/doesnt match
            State 1 : substring c
            state 2 : substring "cb"
            state 3 : substring "cba" -> Accepted
         */
        while (i < len and !possible)
        {

            if (s[i] == 'c')
            {
                stateC();
            }
            else if (s[i] == 'b' and state == 1)
            {

                stateCtoB();
            }
            else if (s[i] == 'a' and state == 2)
            {
                stateBtoA();
            }
            else
            {
                state0();
            }
            i++;
        }

        if (possible)
        {
            cout << "Accepted\n";
        }
        else
        {
            cout << "Rejected\n";
        }
    }
}