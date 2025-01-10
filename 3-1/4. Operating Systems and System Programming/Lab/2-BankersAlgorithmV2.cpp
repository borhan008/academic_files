#include <bits/stdc++.h>
using namespace std;
// It is just another way to implement Banker's Algorithm (different from sir lecture sheet)

bool checkPossiblity(int need[], vector<int> work)
{
    for (int i = 0; i < work.size(); i++)
    {
        if (need[i] > work[i])
            return false;
    }
    return true;
}

int main()
{
    printf("Enter the number of processes and resources\n");
    int process, resources;
    cin >> process >> resources;

    int allocation[process][resources], maxAlloc[process][resources], available[resources], need[process][resources];

    cout << "Enter the allocation matrix\n";
    for (int i = 0; i < process; i++)
        for (int j = 0; j < resources; j++)
            cin >> allocation[i][j];

    cout << "Enter the max allocation matrix\n";
    for (int i = 0; i < process; i++)
        for (int j = 0; j < resources; j++)
            cin >> maxAlloc[i][j];

    cout << "Enter the available matrix\n";
    for (int i = 0; i < resources; i++)
        cin >> available[i];

    for (int i = 0; i < process; i++)
        for (int j = 0; j < resources; j++)
            need[i][j] = maxAlloc[i][j] - allocation[i][j];

    vector<int> permute;
    for (int i = 0; i < process; i++)
        permute.push_back(i);

    bool flag = false;
    do
    {
        vector<int> work(available, available + resources);
        bool finish[process] = {false};
        bool flag2 = true;

        for (int j = 0; j < process; j++)
        {
            if (finish[permute[j]] == false and checkPossiblity(need[permute[j]], work))
            {
                for (int i = 0; i < resources; i++)
                {
                    work[i] += allocation[permute[j]][i];
                }
                finish[permute[j]] = true;
            }
            else
            {
                flag2 = false;
                break;
            }
        }

        if (flag2)
        {
            flag = true;
            break;
        }
    } while (next_permutation(permute.begin(), permute.end()));

    if (flag)
    {
        cout << "Safe sequence is: ";
        for (int i = 0; i < process; i++)
            cout << "P" << permute[i] << " ";
    }
    else
    {
        cout << "No safe sequence exists";
    }
}
/**

5 3

1 1 2
2 1 2
4 0 1
0 2 0
1 1 2

4 3 3
9 0 2
7 5 3
1 1 2
3 2 2

2 1 0
 */