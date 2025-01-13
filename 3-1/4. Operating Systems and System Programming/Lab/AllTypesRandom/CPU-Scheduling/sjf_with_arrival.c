#include <stdio.h>

int main()
{
    int numProcesses, i, j, totalWaitingTime = 0, totalTurnaroundTime = 0, position, temp;
    float avgWaitingTime, avgTurnaroundTime;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    // Declare arrays for burst time, process ID, arrival time, waiting time, and turnaround time
    int burstTime[numProcesses], processId[numProcesses], arrivalTime[numProcesses], waitingTime[numProcesses], turnaroundTime[numProcesses];

    // Input burst time and arrival time for each process
    printf("\nEnter Burst Time and Arrival Time for each process:\n");
    for (i = 0; i < numProcesses; i++)
    {
        printf("Process P%d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        processId[i] = i + 1;
    }

    // Sorting burst times in ascending order (with respect to arrival time as tie-breaker)
    for (i = 0; i < numProcesses; i++)
    {
        position = i;
        for (j = i + 1; j < numProcesses; j++)
        {
            if (arrivalTime[j] < arrivalTime[position] || (arrivalTime[j] == arrivalTime[position] && burstTime[j] < burstTime[position]))
            {
                position = j;
            }
        }

        // Swapping burst time, arrival time, and process ID
        temp = burstTime[i];
        burstTime[i] = burstTime[position];
        burstTime[position] = temp;

        temp = arrivalTime[i];
        arrivalTime[i] = arrivalTime[position];
        arrivalTime[position] = temp;

        temp = processId[i];
        processId[i] = processId[position];
        processId[position] = temp;
    }

    // Initialize the waiting time for the first process
    waitingTime[0] = 0;

    // Calculate the waiting time of all the processes
    for (i = 1; i < numProcesses; i++)
    {
        waitingTime[i] = 0;
        for (j = 0; j < i; j++)
        {
            // Calculate individual waiting time by adding burst time of all previous processes
            waitingTime[i] += burstTime[j];
        }

        // Calculate total waiting time
        totalWaitingTime += waitingTime[i];
    }

    // Average waiting time
    avgWaitingTime = (float)totalWaitingTime / numProcesses;

    // Printing process sequence
    printf("\nProcess Execution Sequence: ");
    for (i = 0; i < numProcesses; i++)
    {
        printf("P%d ", processId[i]);
    }

    // Calculate and print turnaround time for each process
    printf("\n\nProcess\t Burst Time \t Arrival Time \t Waiting Time \t Turnaround Time");
    for (i = 0; i < numProcesses; i++)
    {
        // Calculate turnaround time for individual processes
        turnaroundTime[i] = burstTime[i] + waitingTime[i] - arrivalTime[i];

        // Calculate total turnaround time
        totalTurnaroundTime += turnaroundTime[i];
        printf("\nP%d\t\t %d\t\t %d\t\t %d\t\t\t%d", processId[i], burstTime[i], arrivalTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Average turnaround time
    avgTurnaroundTime = (float)totalTurnaroundTime / numProcesses;

    printf("\n\nAverage Waiting Time = %f", avgWaitingTime);
    printf("\nAverage Turnaround Time = %f", avgTurnaroundTime);

    return 0;
}
