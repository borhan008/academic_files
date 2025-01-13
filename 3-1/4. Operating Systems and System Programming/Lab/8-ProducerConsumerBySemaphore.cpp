#include <bits/stdc++.h>
using namespace std;

int _mutex = 1, full = 0, _empty = 3, x = 0;

int wait(int s)
{
    return --s;
}
int signal(int s)
{
    return ++s;
}
void producer()
{
    _mutex = wait(_mutex);
    full = signal(full);
    _empty = wait(_empty);
    x++;
    cout << "Producer produces the item " << x << endl;
    _mutex = signal(_mutex);
}

void consumer()
{
    _mutex = wait(_mutex);
    full = wait(full);
    _empty = signal(_empty);
    cout << "Consumer consumes item " << x << endl;
    x--;
    _mutex = signal(_mutex);
}

int main()
{
    int n;
    cout << "1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 for Exit\n";
    while (1)
    {
        cout << "Enter your choice\n";
        cin >> n;
        switch (n)
        {
        case 1:
            if ((_mutex == 1) && (_empty != 0))
                producer();
            else
                cout << "Buffer is full\n";
            break;
        case 2:
            if ((_mutex == 1) && (full != 0))
                consumer();
            else
                cout << "Buffer is empty\n";
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
