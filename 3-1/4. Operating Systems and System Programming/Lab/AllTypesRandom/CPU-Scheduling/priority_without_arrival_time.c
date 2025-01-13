#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int b[n], p[n], index[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &b[i], &p[i]);
        index[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        int a = p[i], m = i;

        for (int j = i; j < n; j++)
        {
            if (p[j] > a)
            {
                a = p[j];
                m = j;
            }
        }

        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i], &index[m]);
    }

    int t = 0, total_wait_time = 0, total_turnaround_time = 0;

    printf("Order of process Execution is\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d ", index[i]);
    }
    printf("\n");

    printf("Process Id     Burst Time   Wait Time    TurnAround Time    Completion Time\n");
    for (int i = 0; i < n; i++)
    {
        int wait_time = t;
        int turnaround_time = wait_time + b[i];
        int completion_time = t + b[i];

        printf("P%d             %d            %d             %d                %d\n",
               index[i], b[i], wait_time, turnaround_time, completion_time);

        t += b[i];
        total_wait_time += wait_time;
        total_turnaround_time += turnaround_time;
    }

    float avg_wait_time = (float)total_wait_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
