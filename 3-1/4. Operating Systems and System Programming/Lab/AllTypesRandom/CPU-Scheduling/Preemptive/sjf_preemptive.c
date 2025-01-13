#include <stdio.h>
#include <stdlib.h>

int main()
{
    int processes;
    printf("Enter Number of Processes: ");
    scanf("%d", &processes);

    int process[processes][7];
    // 0 - Process ID
    // 1 - Arrival Time
    // 2 - Burst Time
    // 3 - Waiting Time
    // 4 - Turnaround Time
    // 5 - Completion Time
    // 6 - Current Burst Time

    for (int i = 0; i < processes; i++)
    {
        printf("Enter Arrival Time, Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &process[i][1], &process[i][2]);
        process[i][0] = i + 1;
        process[i][6] = process[i][2];
    }

    int completeProcess = 0;
    int t = 0;
    int finishProcess[processes];
    for (int i = 0; i < processes; i++)
        finishProcess[i] = 0;

    int processOfExecution[1000];
    int processOfExecutionIndex = 0;

    while (completeProcess < processes)
    {
        int findProcess = -1;
        int shortest = 1000000;
        for (int i = 0; i < processes; i++)
        {
            if (process[i][1] <= t && finishProcess[i] == 0 && process[i][6] < shortest)
            {
                shortest = process[i][6];
                findProcess = i;
            }
        }
        process[findProcess][6] -= 1;
        t += 1;
        if (process[findProcess][6] == 0)
        {
            process[findProcess][5] = t;
            process[findProcess][4] = t - process[findProcess][1];
            process[findProcess][3] = process[findProcess][4] - process[findProcess][2];
            finishProcess[findProcess] = 1;
            completeProcess += 1;
        }
        if (processOfExecutionIndex == 0 || processOfExecution[processOfExecutionIndex - 1] != findProcess + 1)
        {
            processOfExecution[processOfExecutionIndex] = findProcess + 1;
            processOfExecutionIndex += 1;
        }
    }

    printf("\nProcess Execution Sequence: ");
    for (int i = 0; i < processOfExecutionIndex; i++)
    {
        printf("P%d ", processOfExecution[i]);
    }

    printf("\nProcess\t Burst \t Arrival \t Waiting \t Turnaround \t Completion\n");
    float totalWaitingTime = 0, totalTurnaroundTime = 0, totalCompletionTime = 0;
    for (int i = 0; i < processes; i++)
    {
        totalWaitingTime += process[i][3];
        totalTurnaroundTime += process[i][4];
        totalCompletionTime += process[i][5];
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", process[i][0], process[i][2], process[i][1], process[i][3], process[i][4], process[i][5]);
    }
    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / processes);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / processes);
    printf("Average Completion Time: %.2f\n", (float)totalCompletionTime / processes);
}

/*
4
0 8
1 4
2 9
3 5
*/