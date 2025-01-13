#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numProcesses, i, j, totalWaitingTime = 0, totalTurnaroundTime = 0, position, temp;
    float avgWaitingTime, avgTurnaroundTime;

    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    // Declare arrays based on the number of processes
    int burstTime[numProcesses], processId[numProcesses], waitingTime[numProcesses], turnaroundTime[numProcesses];

    printf("\nEnter Burst Time for each process:\n");
    for (i = 0; i < numProcesses; i++)
    {
        printf("Process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
        processId[i] = i + 1;
    }

    // Sorting burst times in ascending order
    for (i = 0; i < numProcesses; i++)
    {
        position = i;
        for (j = i + 1; j < numProcesses; j++)
        {
            if (burstTime[j] < burstTime[position])
            {
                position = j;
            }
        }

        // Swapping burst time and process ID
        temp = burstTime[i];
        burstTime[i] = burstTime[position];
        burstTime[position] = temp;

        temp = processId[i];
        processId[i] = processId[position];
        processId[position] = temp;
    }

    waitingTime[0] = 0;

    // Finding the waiting time of all the processes
    for (i = 1; i < numProcesses; i++)
    {
        waitingTime[i] = 0;
        for (j = 0; j < i; j++)
            // Calculating individual waiting time by adding burst time of all previous processes
            waitingTime[i] += burstTime[j];

        // Calculating total waiting time
        totalWaitingTime += waitingTime[i];
    }

    // Average waiting time
    avgWaitingTime = (float)totalWaitingTime / numProcesses;

    // Printing process sequence and details
    printf("\nProcess Execution Sequence: ");
    for (i = 0; i < numProcesses; i++)
    {
        printf("P%d ", processId[i]);
    }

    printf("\n\nProcess\t Burst Time \t Waiting Time \t Turnaround Time");
    for (i = 0; i < numProcesses; i++)
    {
        // Calculating turnaround time for individual processes
        turnaroundTime[i] = burstTime[i] + waitingTime[i];

        // Calculating total turnaround time
        totalTurnaroundTime += turnaroundTime[i];
        printf("\nP%d\t\t %d\t\t %d\t\t\t%d", processId[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Average turnaround time
    avgTurnaroundTime = (float)totalTurnaroundTime / numProcesses;

    printf("\n\nAverage Waiting Time = %f", avgWaitingTime);
    printf("\nAverage Turnaround Time = %f", avgTurnaroundTime);

    return 0;
}
