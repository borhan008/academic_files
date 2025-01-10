#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int processID;
    string state;
};

struct Semaphore
{
    int value;
    queue<Process *> waitingList;
};

/*
Wait() : it checks the shared resource is available. if not the process is blocked until it becomes available.
* semaphore value decreases
* if semaphore "value" is negative -> no resources are available, so the process is blocked/waiting state
*/

void block(Process *p, Semaphore &s)
{
    p->state = "Waiting";
    s.waitingList.push(p);
    printf("Process %d is blocked and in waiting state\n", p->processID);
}

void wait(Semaphore &s, Process *p)
{
    s.value--;
    if (s.value < 0)
    {
        block(p, s);
    }
    else
    {
        p->state = "Running";
        printf("Process %d is running\n", p->processID);
    }
}

/*
Signal() : it relases the shared recourse and making it availale for others.
* it increments the semaphore value.
* if semaphore value is <= 0, it means there are more process are waiting for the resource -> so it wakes up the process.

*/
void wakeup(Semaphore &s)
{
    if (s.waitingList.empty())
        return;
    Process *p = s.waitingList.front();
    s.waitingList.pop();
    printf("Process %d is woken up and ready to run\n", p->processID);
}

void singal(Semaphore &s)
{
    s.value++;
    if (s.value <= 0)
    {
        wakeup(s);
    }
}

int main()
{
    Semaphore sem;
    sem.value = 1;

    Process p1 = {1, "Ready"}, p2 = {2, "Ready"}, p3 = {3, "Ready"};

    wait(sem, &p1);
    wait(sem, &p2);
    singal(sem);
    wait(sem, &p3);
    singal(sem);
}