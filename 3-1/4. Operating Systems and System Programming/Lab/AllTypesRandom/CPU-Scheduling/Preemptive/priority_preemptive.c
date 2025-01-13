#include <stdio.h>
#include <stdlib.h>

int main()
{
    int processes;
    printf("Enter Number of Processes: ");
    scanf("%d", &processes);

    int process[processes][8];
    // 0 - Process ID
    // 1 - Arrival Time
    // 2 - Burst Time
    // 3 - Priority
    // 4 - Waiting Time
    // 5 - Turnaround Time
    // 6 - Completion Time
    // 7 - Current Burst Time

    for (int i = 0; i < processes; i++)
    {
        printf("Enter Arrival Time, Burst Time, and Priority Value for Process %d: ", i + 1);
        scanf("%d %d %d", &process[i][1], &process[i][2], &process[i][3]);
        process[i][0] = i + 1;
        process[i][7] = process[i][2];
    }

    int completeProcess = 0;
    int t = 0;
    int finishProcess[processes];
    for (int i = 0; i < processes; i++)
    {
        finishProcess[i] = 0;
    }

    int processOfExecution[1000];
    int processOfExecutionIndex = 0;

    while (completeProcess < processes)
    {
        int findProcess = -1;
        int curPriority = 1000000;
        for (int i = 0; i < processes; i++)
        {
            if (process[i][1] <= t && finishProcess[i] == 0 && process[i][3] < curPriority)
            {
                curPriority = process[i][3];
                findProcess = i;
            }
        }
        process[findProcess][7] -= 1;
        t += 1;
        if (process[findProcess][7] == 0)
        {
            process[findProcess][6] = t;
            process[findProcess][5] = t - process[findProcess][1];
            process[findProcess][4] = process[findProcess][5] - process[findProcess][2];
            finishProcess[findProcess] = 1;
            completeProcess += 1;
        }
        if (processOfExecutionIndex == 0 || processOfExecution[processOfExecutionIndex - 1] != process[findProcess][0])
        {
            processOfExecution[processOfExecutionIndex++] = process[findProcess][0];
        }
    }

    printf("Process of execution: \n");
    for (int i = 0; i < processOfExecutionIndex; i++)
    {
        printf("P%d ", processOfExecution[i]);
    }
    printf("\n");

    printf("Proces\tArrival\tBurst\tWait\tTurnaround\tCompletion\n");
    float averageWaitingTime = 0;
    float averageTurnaroundTime = 0;
    float averageCompletionTime = 0;
    for (int i = 0; i < processes; i++)

    {
        averageWaitingTime += process[i][4];
        averageTurnaroundTime += process[i][5];
        averageCompletionTime += process[i][6];

        printf("P%d\t%d\t%d\t%d\t%d\t\t%d\n",
               process[i][0], process[i][1], process[i][2], process[i][4], process[i][5], process[i][6]);
    }

    printf("Average Waiting Time: %.2f\n", averageWaitingTime / processes);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime / processes);
    printf("Average Completion Time: %.2f\n", averageCompletionTime / processes);
}

/*
5
0 11 2
5 28 0
12 2 3
2 10 1
9 16 4
*/