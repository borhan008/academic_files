/*
Modify the class and program of the problem 6 such that the program would be able to add
two vectors and display the resultant vector. (You can pass objects as function arguments)

Input:
1 2 3
1 2

*/

#include<bits/stdc++.h>
using namespace std;

class Vector{
	int size;
	float *p;
	
	public:
	Vector(){
		size = 1;
		p = new float[1];
		p[0]=1;
	}
	Vector(int size){
		this->size = size;
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
	
	void add(Vector &v1, Vector &v2){
		
		int sz1 = v1.size;
		int sz2 = v2.size;
		
		size = max(sz1, sz2);
		
		int mn = min(sz1, sz2);
		p = new float[max(sz1, sz2)];
		
		for(int i=0; i < mn; i++){
			p[i] = v1.p[i]+v2.p[i];
		}
		for(int i = min(sz1, sz2); i<size; i++){
			if(sz1 > sz2){
				p[i] = v1.p[i];
			} else p[i]=v2.p[i];
		}
	}
	
	~Vector(){
		delete []p;
	}
};


int main(){
	Vector v1(3), v2(2);
	v2.display();
	
	Vector v3;
	v3.add(v1, v2);
	v3.display();
	
	return 0;
}