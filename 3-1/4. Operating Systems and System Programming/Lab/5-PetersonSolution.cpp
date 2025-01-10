#include <bits/stdc++.h>
using namespace std;

int flag[2];
int turn;
const int MAX = 1e5;
int ans = 0;

void p0()
{
    flag[0] = 1;
    turn = 1;
    while (flag[1] && turn == 1)
        ;
    for (int i = 1; i <= MAX; i++)
    {
        ans++;
    }
    flag[0] = 0;
}

void p1()
{
    flag[1] = 1;
    turn = 0;
    while (flag[0] && turn == 0)
        ;
    // critical section
    for (int i = 1; i <= MAX; i++)
    {
        ans++;
    }
    // exit section
    flag[1] = 0;
}

int main()
{
    // initialization
    flag[0] = 0;
    flag[1] = 0;
    turn = 0;

    thread t1(p0);
    thread t2(p1);
    t1.join();
    t2.join();
    cout << ans << endl;
    return 0;
}

/**
 To check the answer of the above code without Peterson Solution, just comment    while (flag[1] && turn == 1); the line in p0() function and while (flag[0] && turn == 0); the line in p1() function.
 */