#include <stdio.h>
int main()
{
    int AUTO[2000];
    int LB = 1932;
    int UB = 1984;
    for (int i = LB; i <= UB; i++)
    {
        AUTO[i] = 250 + i % 100;
    }
    for (int i = LB; i <= UB; i++)
    {
        printf("%d %d\n", i, AUTO[i]);
    }
    return 0;
}