#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int resources;
/**
 ekhaen available input hocche zeta direct allocation - total theke biyog pawa zay..

 code e kono biyog kora hoy nah


 */
bool checkSafety(int p, int r[], int **allocation, int **need, int available[])
{
    for (int i = 0; i < resources; i++)
    {
        if (r[i] > need[p][i])
        {
            printf("Request is greater than need\n");
            return false;
        }
        if (r[i] > available[i])
        {
            printf("Request is greater than available\n");
            return false;
        }
    }

    for (int i = 0; i < resources; i++)
    {
        available[i] -= r[i];
        allocation[p][i] += r[i];
        need[p][i] -= r[i];
    }

    return true;
}

int main()
{
    printf("Enter the number of processes and resources\n");
    int processes;
    scanf("%d %d", &processes, &resources);

    // Dynamically allocate memory for allocation, maxAlloc, and need matrices
    int **allocation = (int **)malloc(processes * sizeof(int *));
    int **maxAlloc = (int **)malloc(processes * sizeof(int *));
    int available[resources];
    int **need = (int **)malloc(processes * sizeof(int *));

    for (int i = 0; i < processes; i++)
    {
        allocation[i] = (int *)malloc(resources * sizeof(int));
        maxAlloc[i] = (int *)malloc(resources * sizeof(int));
        need[i] = (int *)malloc(resources * sizeof(int));
    }

    printf("Enter the allocation matrix\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter the max allocation matrix\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &maxAlloc[i][j]);

    printf("Enter the available matrix\n");
    for (int i = 0; i < resources; i++)
        scanf("%d", &available[i]);

    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            need[i][j] = maxAlloc[i][j] - allocation[i][j];

    printf("Write the number of requests\n");
    int request;
    scanf("%d", &request);
    while (request--)
    {
        printf("Enter the process number and the request of each of %d resources serially\n", resources);
        int p;
        scanf("%d", &p);  // process
        p--;              // Our indexes are starting from 0, but the process number starts from 1 as per the user
        int r[resources]; // request
        for (int i = 0; i < resources; i++)
            scanf("%d", &r[i]);
        bool pos = checkSafety(p, r, allocation, need, available);
        if (!pos)
        {
            printf("Failed\n");
            return 0;
        }
        else
        {
            printf("Request granted for P%d\n", p + 1);

            // Adding resources if the process is finished
            bool finished = false;
            for (int i = 0; i < resources; i++)
            {
                if (need[p][i] != 0)
                    finished = false;
            }
            if (finished)
            {
                for (int i = 0; i < resources; i++)
                {
                    available[i] += need[p][i];
                }
            }
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < processes; i++)
    {
        free(allocation[i]);
        free(maxAlloc[i]);
        free(need[i]);
    }
    free(allocation);
    free(maxAlloc);
    free(need);

    return 0;
}
