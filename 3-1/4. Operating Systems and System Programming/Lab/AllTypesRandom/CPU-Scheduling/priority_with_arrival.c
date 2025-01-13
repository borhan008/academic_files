#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int processes;
    printf("Enter Number of Processes: ");
    scanf("%d", &processes);

    int burst[processes], priority[processes], arrival[processes], index[processes];
    for (int i = 0; i < processes; i++)
    {
        printf("Enter Arrival Time, Burst Time, and Priority Value for Process %d: ", i + 1);
        scanf("%d %d %d", &arrival[i], &burst[i], &priority[i]);
        index[i] = i + 1;
    }

    for (int i = 0; i < processes; i++)
    {
        int highest_priority = priority[i], earliest_arrival = arrival[i], m = i;

        for (int j = i; j < processes; j++)
        {
            if (priority[j] > highest_priority ||
                (priority[j] == highest_priority && arrival[j] < earliest_arrival))
            {
                highest_priority = priority[j];
                earliest_arrival = arrival[j];
                m = j;
            }
        }

        swap(&priority[i], &priority[m]);
        swap(&burst[i], &burst[m]);
        swap(&arrival[i], &arrival[m]);
        swap(&index[i], &index[m]);
    }

    int t = 0, total_wait_time = 0, total_turnaround_time = 0;
    printf("\nOrder of Process Execution:\n");
    for (int i = 0; i < processes; i++)
    {
        if (t < arrival[i])
        {
            t = arrival[i];
        }
        printf("P%d ", index[i]);
        t += burst[i];
    }

    printf("\n\nProcess Id     Arrival Time     Burst Time     Wait Time     Turnaround Time\n");
    int wait_time = 0;
    for (int i = 0; i < processes; i++)
    {
        if (t < arrival[i])
        {
            t = arrival[i];
        }
        wait_time = t - arrival[i];
        total_wait_time += wait_time;
        int turnaround_time = wait_time + burst[i];
        total_turnaround_time += turnaround_time;
        printf("P%d             %d               %d             %d             %d\n",
               index[i], arrival[i], burst[i], wait_time, turnaround_time);
        t += burst[i];
    }

    float avg_wait_time = (float)total_wait_time / processes;
    float avg_turnaround_time = (float)total_turnaround_time / processes;

    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
