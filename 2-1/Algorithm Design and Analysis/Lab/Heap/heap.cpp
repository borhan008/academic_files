#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, e;	cin >> n >> e;
	vector<int> adj[n+5];
	
	for(int i=1; i<=e; i++){
		int u, v;	cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int source; cin >> source;
	
	queue<int> q;
	vector<int> ans;
	vector<bool> vis(n+2, false);
	
	vis[source] = true;
	q.push(source);
	ans.push_back(source);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(auto v:adj[u]){
			if(vis[v]) continue;
			vis[v]=true;
			ans.push_back(v);
			q.push(v);
		}
	}
	
	for(auto l:ans)	cout << l << " ";
}