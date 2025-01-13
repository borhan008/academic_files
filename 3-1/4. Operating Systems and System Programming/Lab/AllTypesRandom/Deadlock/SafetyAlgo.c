#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

bool checkPossibility(int need[], int work[], int resources)
{
    for (int i = 0; i < resources; i++)
    {
        if (need[i] > work[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    printf("Enter the number of processes and resources\n");
    int processes, resources;
    scanf("%d %d", &processes, &resources);

    // Declare the matrices and arrays
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int maxAlloc[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES];

    printf("Enter the allocation matrix\n");
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the max allocation matrix\n");
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &maxAlloc[i][j]);
        }
    }

    printf("Enter the available matrix\n");
    for (int i = 0; i < resources; i++)
    {
        scanf("%d", &available[i]);
    }

    // Calculate the need matrix
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = maxAlloc[i][j] - allocation[i][j];
        }
    }

    // Initialize finish array to false
    for (int i = 0; i < processes; i++)
    {
        finish[i] = false;
    }

    // Initialize work array to available resources
    for (int i = 0; i < resources; i++)
    {
        work[i] = available[i];
    }

    // Check for safety
    for (int i = 1; i <= resources; i++)
    {
        for (int j = 0; j < processes; j++)
        {
            if (!finish[j] && checkPossibility(need[j], work, resources))
            {
                for (int k = 0; k < resources; k++)
                {
                    work[k] += allocation[j][k];
                }
                finish[j] = true;
            }
        }
    }

    bool safe = true;
    for (int i = 0; i < processes; i++)
    {
        if (!finish[i])
        {
            safe = false;
            break;
        }
    }

    if (safe)
    {
        printf("Safe State.\n");
    }
    else
    {
        printf("Unsafe State\n");
    }

    return 0;
}
