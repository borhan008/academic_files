#include <stdio.h>

void LinearSearch(int LA[], int N, int ITEM)
{
    int LOC = -1;
    for (int i = 0; i < N; i++)
    {
        if (LA[i] == ITEM)
        {
            LOC = i;
            break;
        }
    }
    printf("%d", LOC);
}

int main()
{
    int N = 10;
    // 0 Base indexing
    int LA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinearSearch(LA, N, 9);
}