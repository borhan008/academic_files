/*
Write a program to display names, roll number, and grades of 3 students who have
appeared in the examination. Declare the class of name, roll number and grade. Create an
array of class objects. Read and display the contents of the array.
*/
#include<bits/stdc++.h>
using namespace std;

class Student{
	string name; int roll; double grade;
	
	public:
	void get(string name, int roll, double grade){
		this->name = name;
		this->roll = roll;
		this->grade = grade;
	}
	
	void display(){
		cout << name << " " << roll << " " << grade << "\n";
	}
};

int main(){
	Student students[3];
	string name; int roll; double grade;
	
	for(int i=0; i<3; i++){
		cin >> name >> roll >> grade;
		students[i].get(name, roll, grade);
	}
	
	for(int i=0; i<3; i++){
		students[i].display();
	}
}