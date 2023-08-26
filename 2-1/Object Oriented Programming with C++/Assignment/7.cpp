/*
Define a class to represent a bank account. Include the following members:
	Data members
		i. Name of the depositor
		ii. Account number
		iii. Type of account
		iv. Balance amount in the account
	Member functions
		i. To assign initial values
		ii. To deposit an amount
		iii. To withdraw an amount after checking the balance
		iv. To display name and balance
Write a program to implement these operations.

Input : 
A T1 008 300
B T3 1120 500
C T2 2525 600
D T4 4213 200
E T5 4312 250
F T6 2126 210
G T2 1235 100
H T1 2537 360
I T5 6442 254
J T3 4146 100

4
1 008
2 008 100
3 1120  400
1 1120
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4+5;

class BankAccount{
	string name[MAX], type[MAX], account_number[MAX];
	int balance[MAX];
	int n;
	public:
	BankAccount(){
		n=0;
	}
	
	void get(string nm, string t, string num, int balance){
		name[n] = nm;
		type[n] = t;
		account_number[n] = num;
		this->balance[n] = balance;
		n++;
	}
	
	int check(string acc_num){
		int ind = -1;
		for(int i=0; i<n; i++){
			if(account_number[i]==acc_num){
				ind=i; break;
			}
		}
		
		if(ind == -1) {
			cout << "Acount is not found.\n";
		}		
		return ind;
	}
	
	void deposit(string acc_num, int amount){
		int ind = check(acc_num);
		if(ind == -1) return;
		
		balance[ind]  += amount;
		cout << "The deposit of " << amount << " taka in " << acc_num << " has been executed successfully.\n";
	}	

	void withdraw(string acc_num, int amount){
		int ind = check(acc_num);
		if(ind == -1) return;
				
		if(amount > balance[ind]){
			cout << "You have not sufficient balacne to withdraw " << amount << " \n";
			return;
		}
		balance[ind] -= amount;
		cout << "A withdrawal of "  << amount << " taka was completed successfully.\n";
	}	
	
	
	void display(string acc_num){
		int ind = check(acc_num);
		if(ind == -1) return;
		
		cout << "Name : " << name[ind] << "\n";
		cout << "Balance : " << balance[ind] << "\n";
	}
	

};


int main(){
	string name, acc_number, type; int balance;
	
	BankAccount b;
	for(int i=0; i<10; i++){
		cin >> name >> type >> acc_number >> balance;
		b.get(name, type, acc_number, balance);
	}
	
	int q;	cin >> q;
	cout << "1. Display \n2. Deposit\n3. Withdraw\n";
	
	while(q--){
		int op;	cin >> op;
		
		if(op==1){
			cin >> acc_number;
			b.display(acc_number);
		} else if(op==2){
			cin >> acc_number >> balance;
			b.deposit(acc_number, balance);
		} else if(op == 3){
			cin >> acc_number >> balance;
			b.withdraw(acc_number, balance);			
		}
	}
	
	return 0;
}