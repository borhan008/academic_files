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

Input : Borhan Student 008 100
*/

#include<bits/stdc++.h>
using namespace std;

class BankAccount{
	string name, type, account_number;
	int balance;
	
	public:
	
	void get(string n, string t, string num, int balance){
		name = n;
		type = t;
		account_number = num;
		this->balance = balance;
	}
	
	void deposit(int amount){
		balance  += amount;
		cout << "The deposit of " << amount << " taka has been executed successfully.\n";
	}
	
	void withdraw(int amount){
		if(amount > balance){
			cout << "You have not sufficient balacne to withdraw " << amount << " \n";
			return;
		}
		balance -= amount;
		cout << "A withdrawal of "  << amount << " taka was completed successfully.\n";
	}
	
	void display(){
		cout << "Name : " << name << "\n";
		cout << "Balance : " << balance << "\n";
	}
};


int main(){
	string name, acc_number, type; int balance;
	cin >> name >> type >> acc_number >> balance;
	
	BankAccount b;
	b.get(name, type, acc_number, balance);
	
	b.display();
	
	b.deposit(200);
	b.display();
	
	b.withdraw(299);
	b.display();
	
	b.withdraw(100);
	
	return 0;
}