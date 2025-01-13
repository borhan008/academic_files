#include <stdio.h>
#include <stdbool.h>

/**
 ekhaen available input hocche zeta direct allocation - total theke biyog pawa zay..

 code e kono biyog kora hoy nah


 */

bool checkPossibility(int need[], int work[], int resources)
{
    for (int i = 0; i < resources; i++)
    {
        if (need[i] > work[i])
            return false;
    }
    return true;
}

int main()
{
    printf("Enter the number of processes and resources\n");
    int processes, resources;
    scanf("%d %d", &processes, &resources);

    int allocation[processes][resources], maxAlloc[processes][resources], available[resources], need[processes][resources];

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

    int ans[processes];
    bool finish[processes];
    for (int i = 0; i < processes; i++)
        finish[i] = false;

    int work[resources];
    for (int i = 0; i < resources; i++)
        work[i] = available[i];

    int ansIndex = 0;

    for (int i = 0; i < resources; i++)
    {
        for (int j = 0; j < processes; j++)
        {
            if (finish[j] == false && checkPossibility(need[j], work, resources))
            {
                for (int k = 0; k < resources; k++)
                {
                    work[k] += allocation[j][k];
                }
                ans[ansIndex++] = j;
                finish[j] = true;
            }
        }
    }

    bool flag = true;
    for (int i = 0; i < processes; i++)
    {
        if (!finish[i])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        printf("Safe sequence is: ");
        for (int i = 0; i < processes; i++)
            printf("P%d ", ans[i]);
    }
    else
    {
        printf("No safe sequence exists");
    }

    return 0;
}
