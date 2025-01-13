#include <bits/stdc++.h>
using namespace std;
int main()
{
	printf("Enter the number of processes\n");
	int processes;
	cin >> processes;

	int ans[processes + 1][6];
	int current[processes + 1];

	queue<int> r; // Ready Queue

	for (int i = 0; i < processes; i++)
	{
		cout << "Write arrival time and burst time for " << i + 1 << "\n";
		int arrival, burst;
		cin >> arrival >> burst;
		current[i] = burst;
		ans[i][0] = arrival;
		ans[i][1] = burst;
		if (arrival == 0)
			r.push(i);
		ans[i][5] = INT_MAX;
	}

	int quantum = 2;
	cout << "Write the quantum time ";
	cin >> quantum;
	int sum = 0;

	while (!r.empty())
	{
		int i = r.front();
		r.pop();
		if (current[i] == 0)
			continue;

		int x = min(current[i], quantum);

		ans[i][5] = min(ans[i][5], sum);
		current[i] -= x;

		for (int j = 0; j < processes; j++)
		{
			if (ans[j][0] > sum && ans[j][0] <= sum + x)
			{
				r.push(j);
			}
		}

		if (current[i] != 0)
			r.push(i);
		else
		{
			ans[i][2] = sum + x;			   // Completion Time
			ans[i][3] = ans[i][2] - ans[i][0]; // Turnaround Time
			ans[i][4] = ans[i][3] - ans[i][1]; // Waiting Time
			ans[i][5] = ans[i][5] - ans[i][0]; // Response Time
		}

		sum += x;
	}

	cout << "\nProcess\tArrive\tBurst\tCT\tTAT\tWT\tRT\n";
	for (int i = 0; i < processes; i++)
	{
		cout << "P" << i + 1 << "\t";
		for (int j = 0; j < 6; j++)
		{
			cout << ans[i][j] << "\t";
		}
		cout << "\n";
	}
}
