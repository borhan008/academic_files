/*
Assume that the test results of a batch of students are stored in three different classes. Class
student stores the roll-number, class test stores the marks obtained in two subjects and
class result contains the total marks obtained in the test. The class result can inherit the
details of the marks obtained in the test and the roll-number of students through multilevel
inheritance.
Write a program to display the result of a student.
*/

#include<bits/stdc++.h>
using namespace std;

class student{
	protected:
		int roll;
	
	public:
	student(){
		cout << "Input Roll : \n";
		cin >> roll;
	}
};

class test{
	protected:
	int num1, num2;
	
	public:
	test(){
		cout << "Input subject 1 and 2 marks respectively\n";
		cin >> num1 >> num2;
	};	
};

class result : public student, public test{
	int totalMarks;
	
	public:
	result() {
		totalMarks = num1+num2;
	}
	void display(){
		cout << "\nRoll : " << roll << "\n";
		cout << "Marks in two subject : " << num1 << ", " << num2 << "\n";
		cout << "Total Marks : " << totalMarks << "\n";
	}
};

int main(){
	
	result res;
	res.display();
}