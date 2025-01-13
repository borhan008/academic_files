#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10
/**

Ekhane available = ekkebare allocation na thakle ba total available
availabe ber korte allocation thekle biyog korte hobe.

 *
 */
// resource allocation
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int request[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int resources[MAX_RESOURCES];
int work[MAX_RESOURCES];
int marked[MAX_PROCESSES];

int main()
{
    int num_processes, num_resources;

    // Input number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    // Input total resources
    for (int i = 0; i < num_resources; i++)
    {
        printf("Enter the total amount of Resource R%d: ", i + 1);
        scanf("%d", &resources[i]);
    }

    // Input request matrix
    printf("Enter the request matrix:\n");
    for (int i = 0; i < num_processes; i++)
    {
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < num_processes; i++)
    {
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Calculate available resources
    for (int j = 0; j < num_resources; j++)
    {
        available[j] = resources[j];
        for (int i = 0; i < num_processes; i++)
        {
            available[j] -= allocation[i][j];
        }
    }

    // Mark processes with zero allocation
    for (int i = 0; i < num_processes; i++)
    {
        int count = 0;
        for (int j = 0; j < num_resources; j++)
        {
            if (allocation[i][j] == 0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count == num_resources)
        {
            marked[i] = 1;
        }
        else
        {
            marked[i] = 0;
        }
    }

    // Initialize work with available resources
    for (int j = 0; j < num_resources; j++)
    {
        work[j] = available[j];
    }

    // Mark processes whose requests can be satisfied with available resources
    for (int i = 0; i < num_processes; i++)
    {
        int can_be_processed = 1;
        if (marked[i] != 1)
        {
            for (int j = 0; j < num_resources; j++)
            {
                if (request[i][j] > work[j])
                {
                    can_be_processed = 0;
                    break;
                }
            }
            if (can_be_processed)
            {
                marked[i] = 1;
                for (int j = 0; j < num_resources; j++)
                {
                    work[j] += allocation[i][j];
                }
            }
        }
    }

    // Check for unmarked processes (indicating deadlock)
    int deadlock = 0;
    for (int i = 0; i < num_processes; i++)
    {
        if (marked[i] != 1)
        {
            deadlock = 1;
            break;
        }
    }

    if (deadlock)
    {
        printf("Deadlock detected\n");
    }
    else
    {
        printf("No deadlock possible\n");
    }

    return 0;
}

/**

4 4
6 9 6 9

3 4 4 5
2 2 2 2
1 2 2 1
2 2 4 3

2 3 2 3
1 1 0 2
1 2 0 1
0 1 1 0
 */