#include <bits/stdc++.h>
using namespace std;

int resources;

bool checkSafety(int p, int *r, int **allocation, int **need, int *available)
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

    /*
    * If there's a situation where the process need[p][i] = 0 and we can make the resources of the process p available again (Though it is not a step in Resource Request Algorithm as per sir's lecture sheet)
    if(need[p][i] == 0){
        for(int i = 0; i < resources; i++){
            available[i] += allocation[p][i];
            allocation[p][i] = 0;
        }
    }
    */
    return true;
}

int main()
{
    printf("Enter the number of processes and resources\n");
    int processes;
    cin >> processes >> resources;

    /*
            Why are we using pointers?
        => Because we want to change the values of the matrices or arrays in the function checkSafety.
    */
    int **allocation = new int *[processes];
    int **maxAlloc = new int *[processes];
    int available[resources];
    int **need = new int *[processes];

    for (int i = 0; i < processes; i++)
    {
        allocation[i] = new int[resources];
        maxAlloc[i] = new int[resources];
        need[i] = new int[resources];
    }

    cout << "Enter the allocation matrix\n";
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            cin >> allocation[i][j];

    cout << "Enter the max allocation matrix\n";
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            cin >> maxAlloc[i][j];

    cout << "Enter the available matrix\n";
    for (int i = 0; i < resources; i++)
        cin >> available[i];

    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            need[i][j] = maxAlloc[i][j] - allocation[i][j];

    printf("Write the number of requests\n");
    int request;
    cin >> request;
    while (request--)
    {
        printf("Enter the process number and the request of each of %d resources serially\n", request);
        int p;
        cin >> p;         // process
        p--;              // Our indexes are starting from 0, but the process number starts from 1 as per the user
        int r[resources]; // request
        for (int i = 0; i < resources; i++)
            cin >> r[i];
        bool pos = checkSafety(p, r, allocation, need, available);
        if (!pos)
        {
            cout << "Failed" << "\n";
            return 0;
        }
        else
        {
            cout << "Request granted for " << p + 1 << "\n";
        }
    }

    return 0;
}