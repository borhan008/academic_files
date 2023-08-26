/*
Create two classes DM and DB which store the value of distances. DM stores distances in
metres and centimeters and DB in feet and inches. Write a program that can read values for
the class objects and add one objects of DM with another object of DB.
Use a friend function to carry out the addition operation. The object that stores the results
may be a DM object or DB object, depending on the units in which the results are required.
The display should be in the format of feet and inches or metres and centimeters depending
on the objects on display.

Input:
10 12
13 14
*/

#include<bits/stdc++.h>
using namespace std;

class DB;

class DM {
	double m, cm;
	
	public:
	DM(){
		m=0; cm=0;
	}
	void get(double x, double y){
		m=x; cm=y;
	}
	double fttom(double x){
		return x*0.3048;
	}
	double inchtocm(double x){
		return x*2.54;
	}
	void display(){
		cout << m << " m " << cm << " cm\n";
	}	
	friend void add(DM &dm, DB &db);
};

class DB {
	double ft, inch;
	
	public:
	DB(){
		ft=0; inch=0;
	}
	void get(double x, double y){
		ft=x; inch=y;
	}
	double mtoft(double x){
		return x*3.28;
	}
	double cmtoinch(double x){
		return x/2.54;
	}
	void display(){
		cout << ft << " feet " << inch << " inch\n";
	}
	friend void add(DM &dm, DB &db);
};

void add(DM &dm, DB &db){
	DM d1;
	d1.m = dm.m + d1.fttom(db.ft);
	d1.cm = dm.cm + d1.inchtocm(db.inch);
	
	DB d2;
	d2.ft = db.ft + d2.mtoft(dm.m);
	d2.inch = db.inch + d2.cmtoinch(dm.cm);
	
	d1.display();
	d2.display();
}

int main(){
	DM dm; DB db;
	
	double x, y;
	cout << "Input m and cm: \n";
	cin >> x >> y; dm.get(x, y);
	cout << "Input feet and inch: \n";
	cin >> x >> y; db.get(x, y);	
	
	add(dm, db);
}