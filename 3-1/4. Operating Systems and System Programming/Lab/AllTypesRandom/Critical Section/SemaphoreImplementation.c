#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

// Process structure
struct Process
{
    int processID;
    char state[10]; // "Running", "Waiting", "Ready"
};

// Semaphore structure
struct Semaphore
{
    int value;
    struct Process *waitingList[MAX_PROCESSES]; // Array of pointers to waiting processes
    int front, rear;
};

// Function to block a process and add it to the waiting list
void block(struct Process *p, struct Semaphore *s)
{
    strcpy(p->state, "Waiting");
    s->waitingList[s->rear++] = p;
    printf("Process %d is blocked and in waiting state\n", p->processID);
}

// Function for Wait() operation on a semaphore
void wait(struct Semaphore *s, struct Process *p)
{
    s->value--;
    if (s->value < 0)
    {
        block(p, s);
    }
    else
    {
        strcpy(p->state, "Running");
        printf("Process %d is running\n", p->processID);
    }
}

// Function to wake up a process from the waiting list
void wakeup(struct Semaphore *s)
{
    if (s->front == s->rear)
        return;
    struct Process *p = s->waitingList[s->front++];
    printf("Process %d is woken up and ready to run\n", p->processID);
}

// Function for Signal() operation on a semaphore
void signal(struct Semaphore *s)
{
    s->value++;
    if (s->value <= 0)
    {
        wakeup(s);
    }
}

int main()
{
    // Initialize semaphore with value 1
    struct Semaphore sem;
    sem.value = 1;
    sem.front = sem.rear = 0;

    // Initialize processes
    struct Process p1 = {1, "Ready"}, p2 = {2, "Ready"}, p3 = {3, "Ready"};

    // Demonstrate the semaphore operations
    wait(&sem, &p1);
    wait(&sem, &p2);
    signal(&sem);
    wait(&sem, &p3);
    signal(&sem);

    return 0;
}
