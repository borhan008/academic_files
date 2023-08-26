/*
Consider a shopping list of items for which you place an order with a dealer every month.
The list includes details such as the code number and price of each item. You will perform
the operations such as adding an item to the list, deleting an item from the list and printing
the total value of the order. Write a program to implement these operations using a class
with arrays as data members
*/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+5;

class Order{
	pair<int, double> arr[MAX];
	int n;
	
	public:
	Order(){
		n=0;
	}
	
	void addOrder(int code, double price){
		arr[n] = make_pair(code, price);
		n++;
	}
	
	void deleteOrder(int code){
		int ind=-1;
		for(int i=0; i<n; i++){
			if(arr[i].first == code){
				ind = i;	break;
			}
		}
		for(int i=ind; i<n; i++){
			arr[i]=arr[i+1];
		}
		n--;
	}
	
	void display(){
		cout << n << "\n";
		for(int i=0; i<n; i++){
			int code  = arr[i].first;	
			int price = arr[i].second;
			cout << code << " " << price << "\n";
		}
	}
		
};


int main(){
	cout << "1 - Adding Items\n2 - Deleting Item \n3 - Display\n";
	int t;	cin >> t;
	Order order;
	while(t--){
		int operation;	cin >> operation;
		int code; 	double price;
		
		if(operation == 1){
			cin >> code >> price;
			order.addOrder(code, price);
		} else if(operation == 2){
			cin >> code;
			order.deleteOrder(code);
		} else{
			order.display();
		}
	}
}