#include <stdio.h>
int main()
{
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int LB = 0;
    const int UB = 10;
    while (LB < UB)
    {
        printf("%d ", arr[LB]);
        LB++;
    }
}