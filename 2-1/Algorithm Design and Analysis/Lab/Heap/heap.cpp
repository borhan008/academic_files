#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD

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
=======
#define MAX (int)1e5+5


class Heap{
	int arr[MAX+5];
	int size;
	
	public:
	Heap(){
		arr[0]=-1;
		size=0;
	}
	
	void print(){
		for(int i=1; i<=size; i++)	cout << arr[i] << " ";
	}
	
	void push(int n){
		size++;
		if(size >= MAX){
			size--;
			cout << "Heap is full.";
			return;
		}
		
		int i = size;
		arr[size]=n;
		
		while(i > 1){
			int parent = i/2;
			if(arr[parent] < arr[i]){
				swap(arr[parent], arr[i]);
				i=parent;
			} else return;
		}
	}
	
	void pop(int n){
		arr[1]=arr[size];
		size--;
		
		int i=1;
		while(i < size){
			bool change=false;
			int left = i*2;
			int right = i*2 + 1;
			if(left <= size && arr[i] < arr[left]){
				swap(arr[i], arr[left]);
				i = left;
				change = true;
			}
			if(right <= size && arr[i] < arr[right]){
				swap(arr[i], arr[right]);
				i=right;
				change = true;
			}
			if(change) return;;
		}
		
	}
	
};


int main(){
	int n; cin >> n;
	Heap hp;
	while(n--){
		int x, y;	cin >> x;
		if(x==1){
			//push
			cin >> y;
			hp.push(y);
		} else if(x==2){
			
			
		} else{
			//print
			hp.print();
		}
	}
	return 0; 
>>>>>>> d3d00762f3a6616a87c335c9241aebcd6d5d4f34
}