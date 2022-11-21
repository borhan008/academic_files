#include <stdio.h>

int INSERT(int LA[], int N, int K, int ITEM)
{
    for (int i = N; i > K; i--)
    {
        LA[i] = LA[i - 1];
    }
    LA[K] = ITEM;
    return (N + 1);
}

int main()
{
    int N = 10;
    // 0 Base Indexing
    int LA[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    N = INSERT(LA, N, 5, 105);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", LA[i]);
    }
    return 0;
}