#include <stdio.h>
int main()
{
    int N = 10;
    int LA[10] = {10, 9, 8, 7, 6, 5, 4, 1, 2, 3};

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (LA[j] > LA[j + 1])
            {
                int temp = LA[j];
                LA[j] = LA[j + 1];
                LA[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++)
        printf("%d ", LA[i]);
    return 0;
}