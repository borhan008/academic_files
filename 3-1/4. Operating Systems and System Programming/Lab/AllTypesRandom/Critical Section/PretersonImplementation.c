#include <stdio.h>
#include <pthread.h>

int flag[2];
int turn;
const int MAX = 1e5;
int ans = 0;

void *p0(void *arg)
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
    return NULL;
}

void *p1(void *arg)
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
    return NULL;
}

int main()
{
    // initialization
    flag[0] = 0;
    flag[1] = 0;
    turn = 0;

    pthread_t t1, t2;

    pthread_create(&t1, NULL, p0, NULL);
    pthread_create(&t2, NULL, p1, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("%d\n", ans);

    return 0;
}
