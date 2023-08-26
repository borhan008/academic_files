/*
Assume that a bank maintains two kinds of accounts for customers, one called as savings
account and the other as current account. The savings account provides compound interest
and withdrawal facilities but no cheque book facility. The current account provides cheque
book facility but no interest. Current account holders should also maintain a minimum balance and if the balance falls below this level, a service charge is imposed.
Create a class account that stores customer name, account number and type of account.
From this derive the classes cur_acct and sav_acct to make them more specific to their
requirements. Include necessary member functions in order to achieve the following tasks:
	i. Accept deposit from a customer and update the balance.
	ii. Display the balance.
	iii. Compute and deposit interest.
	iv. Permit withdrawal and update the balance.
	v. Check for the minimum balance, impose penalty and update the balance.
*/
#include<bits/stdc++.h>
using namespace std;

class account{
	protected:
	string name, acc_num, acc_type;
	int balance;
	
	public:
	account(string name, string acc_num, string acc_type, int balance){
		this->name = name;
		this->acc_num = acc_num;
		this->acc_type = acc_type;
		this->balance = balance;
	}
	
	void deposit(int amount){
		balance += amount;
		cout << "A deposit to " << acc_num << " executed successfully\n";
	}
	
	void display(){
		cout << "Balance : " << balance << "\n";
	}
	
	
};

class cur_acct : public account{
	int interest_rate, min_balance, penalty;
	public:
	cur_acct(string name, string acc_num, string acc_type, int balance, int rate, int min_balance, int penalty) : account(name, acc_num, acc_type, balance){
		interest_rate=rate;
		this->min_balance = min_balance;
		this->penalty = penalty;
	}
	
	void checkInterest(){
		int interest = (interest_rate/100)*balance;
		balance += interest;
		cout << "New balance : " << balance << "\n";
	}
	
	void checkPenalty(){
		if(balance < min_balance){
			balance -= penalty;
			cout << "Penalty for having less than minimum balance.\n";
		} else{
			cout << "No penalty\n";
		}
	}
	
	void withdraw(int amount){
		if(amount > balance){
			cout << "Your balance is insufficient.\n";
		} else{
			balance -= amount;
			cout << "Withdraw successfull\n";
		}
	}	
	
};

class sav_acct : public account{
	
	public:
	sav_acct(string name, string acc_num, string acc_type, int balance) : account(name, acc_num, acc_type, balance){
		
	}	
	
	void withdraw(int amount){
		if(amount > balance){
			cout << "Balance is insufficient to withdraw\n";
		} else{
			balance -= amount;
			cout << "Withdraw Successfully\n";
		}
	}
};

int main(){
	cout << "Saving account \n";
	sav_acct acc1("Borhan", "008", "Saving", 1000);
	acc1.display();
	acc1.deposit(200);
	acc1.display();
	acc1.withdraw(500);
	acc1.display();
	acc1.withdraw(701);
	
	cout << "\n\nCurrent account \n";
	cur_acct acc2("Borhan", "0100", "Current", 500, 40, 300, 20);
	acc2.display();
	acc2.checkPenalty();
	acc2.deposit(400);
	acc2.withdraw(200);
	acc2.display();
	acc2.withdraw(405);
	acc2.display();
	acc2.checkPenalty();
	acc2.display();
	
}
