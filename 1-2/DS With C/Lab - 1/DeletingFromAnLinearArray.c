#include <stdio.h>
int DELETE(int LA[], int N, int K)
{
    for (int i = K; i < N; i++)
    {
        LA[i] = LA[i + 1];
    }
    return (N - 1);
}
int main()
{
    int N = 10;
    // 0 Base Indexing
    int LA[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    N = DELETE(LA, N, 5);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", LA[i]);
    }
    return 0;
}