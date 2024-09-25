#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int ans[n+1][6];
	int p[n+1];
	queue<int> r;
	for(int i=0; i<n; i++){
		cout << "Write arrival time and burst time for " << i+1 << "\n";
		int x, y; cin >> x >> y;
		p[i]=y;
		ans[i][0]=x;
		ans[i][1]=y;
		if(x==0)  r.push(i);
		ans[i][5] = INT_MAX;
	}
	
	int qunt=2;
	cout << "Write the quantime time "; cin >> qunt;
	int sum = 0;
	while(!r.empty()){
		int i = r.front(); r.pop();
		int x = min(p[i], qunt);
	
		ans[i][5] = min(ans[i][5], sum); 		
		p[i] -= x;

		for(int j=0; j<n; j++){
			if(ans[j][0] > sum and ans[j][0] <= sum+x){
				r.push(j);
			}
		} 
		
		if(p[i] != 0) r.push(i);
		else {
			ans[i][2] = sum+x; 
			ans[i][3] =  ans[i][2] - ans[i][0];
			ans[i][4] =  ans[i][3] - ans[i][1];
			ans[i][5] = ans[i][5] - ans[i][0];
		}	
			
		sum += x;
	}
	
	cout << "\nProcess\tArrive\tBurst\tCT\tTAT\tWT\tRT\n";
	for(int i=0; i<n; i++){
		cout << "P" << i+1 << "\t";
		for(int j=0; j<6; j++){
			cout << ans[i][j] << "\t";
		}
		cout << "\n";
	}
	
	
}