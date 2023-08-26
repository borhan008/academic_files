/*
Write a program to manipulate complex numbers using operator overloading.
Complex Number: a+bi
(a+ib)+(c+id) = (a+c) + i(c+d)
(a+ib)-(c+id) = (a-c) + i(a-d)
(a+ib)*(c+id) = (ac-bd)+i(ad+bc)
(c+id)/(a+ib) = ((ca + bd) + (ad - cb)i)/(a^2 + b^2)
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
	
	Complex operator*(const Complex &a){
		Complex x;
		x.i = (i*a.i - j*a.j);
		x.j = (i*a.j + j*a.i);
		
		return x;
	}
	
	Complex operator/(const Complex &y){
		Complex x;
		double a=y.i; double b=y.j;
		double c=i;	double d=j;
		x.i = (c*a + b*d)/(a*a + b*b);
		x.j = (a*d - c*b)/(a*a - c*b);
		
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
	
	c = a*b;
	c.display();
	
	c = a/b;
	c.display();
	
	c=a;
	c.display();
}