/*
Consider the long term deposit schemes working in the commercial banks. The banks
provide different interest rates for different schemes as well as for different periods of
investment. Write a program that contains the class variables (Principal amount, period of
investment, Interest rate and Return value of amount) for holding account details and
display the principal amount and return value.

Return Value formulae: A = P(1 + r)^n [ interest is compounded annually]

*/

#include<bits/stdc++.h>
using namespace std;

class Bank{
	double principle, interest_rate, return_value, year;
	
	public:
	Bank(){
		cout << "Input Principle amount, interest rate and year of investment\n";
		cin >> principle >> interest_rate >> year;
		return_value = principle*pow(1+(interest_rate/100), year);
	}
	
	void display(){
		cout << "Principle Amount : " << principle << "\n";
		cout << "Return value: " << return_value << "\n";
	}
};

int main(){
	Bank bn;
	bn.display();
		
	return 0;
}