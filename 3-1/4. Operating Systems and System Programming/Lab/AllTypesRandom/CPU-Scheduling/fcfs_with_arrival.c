#include <stdio.h>

int main()
{
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare arrays with size 'n' based on user input
    int processes[n];       // Process IDs
    int burst_time[n];      // Burst times
    int arrival_time[n];    // Arrival times
    int waiting_time[n];    // Waiting times
    int turnaround_time[n]; // Turnaround times
    int completion_time[n]; // Completion times

    printf("Enter process IDs of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processes[i]);
    }

    printf("Enter burst time of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burst_time[i]);
    }

    printf("Enter arrival time of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrival_time[i]);
    }

    // Initialize waiting time for the first process
    waiting_time[0] = 0;

    // Calculating waiting time for each process
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

    // Calculating completion time and turnaround time
    for (int i = 0; i < n; i++)
    {
        completion_time[i] = waiting_time[i] + burst_time[i];
        turnaround_time[i] = completion_time[i] - arrival_time[i];
    }

    // Printing the process execution schedule
    printf("\nProcess Execution Schedule:\n");
    int start_time = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d is executed from %d to %d\n", processes[i], start_time, start_time + burst_time[i]);
        start_time += burst_time[i];
    }

    // Printing process details
    printf("\nProcess ID   Arrival Time   Burst Time   Completion Time   Waiting Time   Turnaround Time\n");
    float total_waiting_time = 0.0, total_turnaround_time = 0.0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d          %d              %d            %d                %d              %d\n",
               processes[i], arrival_time[i], burst_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);

        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Calculating average waiting time and turnaround time
    float average_waiting_time = total_waiting_time / n;
    float average_turnaround_time = total_turnaround_time / n;

    printf("\nAverage Waiting Time = %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time = %.2f\n", average_turnaround_time);

    return 0;
}
