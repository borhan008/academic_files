#include <stdio.h>
void BinarySearch(int LA[], int N, int ITEM)
{
    int LB = 0;
    int UB = N - 1;
    int LOC = -1;
    while (UB >= LB)
    {
        int mid = (UB + LB) / 2;
        if (LA[mid] == ITEM)
        {
            LOC = mid;
            break;
        }
        else if (LA[mid] > ITEM)
        {
            UB = mid - 1;
        }
        else
        {
            LB = mid + 1;
        }
    }
    printf("%d", LOC);
}
int main()
{
    int N = 10;
    int LA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinarySearch(LA, N, 101);
}