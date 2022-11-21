#include <stdio.h>
int main()
{
    int AUTO[2000];
    int LB = 1932;
    int UB = 1984;
    int NUM = 0;
    for (int i = LB; i <= UB; i++)
    {
        AUTO[i] = 250 + i % 100;
    }
    for (int i = LB; i <= UB; i++)
    {
        if (AUTO[i] > 300)
            NUM++;
    }
    printf("%d", NUM);
    return 0;
}