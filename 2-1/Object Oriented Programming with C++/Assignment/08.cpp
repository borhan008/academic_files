/*
Write a class to represent a vector (a series of float values). Include member functions to
perform the following tasks:
	i. To create the vector
	ii. To modify the value of a given element
	iii. To multiply by a scalar value
	iv. To display the vector in the form (10, 20, 30, …)
	Write a program to implement these operations.
	
Input:
3
1 2 3

*/

#include<bits/stdc++.h>
using namespace std;

class Vector{
	int size;
	float *p;
	
	public:
	
	Vector(){
		cin >> size;
		p = new float [size];
		
		for(int i=0; i<size; i++)
			cin >> p[i];
	}
	
	void modify(int n, int value){
		p[n-1]=value;
	}

	void multiply(int n){
		for(int i=0; i<size; i++){
			p[i] *= n;
		}
	}
	
	void display(){
		for(int i=0; i<size; i++){
			cout << p[i] << " ";
		}
		cout << "\n";
	}
	
	~Vector(){
		delete []p;
	}
};


int main(){
	Vector v;
	
	v.display();
	
	v.multiply(10);
	v.display();
	
	v.modify(2, 6);
	v.display();
	return 0;
}