// Producer-Consumer Problem using Peterson Solution
#include <bits/stdc++.h>
using namespace std;

vector<int> buffer;
int cnt = 0;
const int BUFFER_SIZE = 5;
int flag[2] = {0, 0};
int turn = 0;

void producer()
{
    for (int i = 1; i <= 1000; i++)
    {
        flag[0] = 1;
        turn = 1;
        while (flag[1] && turn == 1)
            ;
        if (cnt == BUFFER_SIZE)
        {
            flag[0] = 0;
            printf("Buffer is full. Producer is waiting\n");
            this_thread::sleep_for(chrono::milliseconds(1000));
            flag[0] = 1;
        }
        buffer.push_back(i);
        cnt++;
        cout << "Produced " << i << endl;
        flag[0] = 0;
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void consumer()
{
    for (int i = 1; i <= 1000; i++)
    {
        flag[1] = 1;
        turn = 0;
        while (flag[0] && turn == 0)
            ;

        if (cnt == 0)
        {
            flag[1] = 0;
            printf("Buffer is empty. Consumer is waiting\n");
            this_thread::sleep_for(chrono::milliseconds(1000));
            flag[1] = 1;
        }

        int product = buffer.front();
        buffer.erase(buffer.begin());
        cnt--;
        cout << "Consumed " << product << endl;
        flag[1] = 0;
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main()
{
    thread p(producer), c(consumer);
    p.join();
    c.join();
    return 0;
}