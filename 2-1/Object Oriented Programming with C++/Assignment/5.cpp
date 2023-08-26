/*
Write a program to perform the addition of time in the hour and minutes format. Use a class
time and a function sum( ) that takes two objects as arguments.
*/

#include<bits/stdc++.h>
using namespace std;

class Time{
	int hour, minute;
	
	public:
	Time(){
		hour=minute=0;
	}
	
	void get(){
		cin >> hour >> minute;
	}
	
	void sum(Time t1, Time t2){
		int totalHour = t1.hour + t2.hour;
		int totalMinute = t1.minute + t2.minute;
		this->hour = totalHour + (totalMinute/60);
		this->minute = totalMinute%60;
	}
	
	void display(){
		cout << hour << " hours " << minute << " minutes\n";
	}
};

int main(){
	Time t1, t2, t3;
	
	t1.get();
	t2.get();
	t3.sum(t1, t2);
	
	t1.display();
	t2.display();
	t3.display();
	
	return 0;
}