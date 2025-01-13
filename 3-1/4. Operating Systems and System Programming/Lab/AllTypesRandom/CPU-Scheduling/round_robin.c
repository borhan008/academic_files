#include <stdio.h>

int main()
{
    int processes; // Number of processes
    printf("Enter Total Number of Processes: ");
    scanf("%d", &processes);

    int wait_time = 0, ta_time = 0;
    int arr_time[processes], burst_time[processes], temp_burst_time[processes];
    int completion_time[processes];
    int remaining_processes = processes;

    for (int i = 0; i < processes; i++)
    {
        printf("Enter Details of Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arr_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i];
    }

    int time_slot;
    printf("Enter Time Slot: ");
    scanf("%d", &time_slot);

    int total_time = 0, counter = 0, i;
    printf("\nProcess Sequence:\n");

    printf("\nProcess ID   Burst Time   Completion Time   Turnaround Time   Waiting Time\n");
    for (total_time = 0, i = 0; remaining_processes != 0;)
    {
        if (temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0)
        {
            total_time += temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
        }
        else if (temp_burst_time[i] > 0)
        {
            temp_burst_time[i] -= time_slot;
            total_time += time_slot;
        }

        if (temp_burst_time[i] == 0 && counter == 1)
        {
            remaining_processes--;
            completion_time[i] = total_time;

            int turnaround_time = total_time - arr_time[i];
            int waiting_time = turnaround_time - burst_time[i];

            printf("P%d          %d             %d                 %d                %d\n",
                   i + 1, burst_time[i], completion_time[i], turnaround_time, waiting_time);

            wait_time += waiting_time;
            ta_time += turnaround_time;
            counter = 0;
        }

        if (i == processes - 1)
        {
            i = 0;
        }
        else if (arr_time[i + 1] <= total_time)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    float average_wait_time = (float)wait_time / processes;
    float average_turnaround_time = (float)ta_time / processes;

    printf("\nAverage Waiting Time: %.2f", average_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}
