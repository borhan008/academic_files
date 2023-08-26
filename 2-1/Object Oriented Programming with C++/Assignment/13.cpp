/*
Write a C++ program to overload +, - and = operators.
Complex Number: a+bi
*/

#include<bits/stdc++.h>
using namespace std;

class Complex{
	double i,j;
	
	public:
	Complex(){
		i=0; j=0;
	}
	
	void get(){
		cout << "Input real and imaginary part:\n";
		cin >> i >> j;
	}
	
	Complex operator+(const Complex &a){
		Complex x;
		x.i = i + a.i;
		x.j = j+a.j;
		return x;
	}
	
	void operator=(const Complex &b){
		i=b.i;
		j=b.j;
	}
	
	Complex operator-(const Complex &a){
		Complex x;
		x.i = i - a.i;
		x.j = j - a.j;
		return x;
	}
	
	void display(){
		cout << i << (j >= 0 ? "+" : "-") << abs(j) << "i" << "\n";
	}
};

int main(){
	Complex a, b;
	a.get(); b.get();
	
	Complex c;
	c = a+b;
	c.display();
	
	c = a-b;
	c.display();
	
	c=a;
	c.display();
}