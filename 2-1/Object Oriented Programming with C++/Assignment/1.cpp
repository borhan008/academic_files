/*
Write a functions power() to raise a number m to a power n. The function takes a double
value for m and int value for n, and returns the result correctly. Use a default value of 2 for
n to take the function to calculate squares when this argument is omitted. Write a program
where main function gets the values of m and n from the user to test the function
*/
#include<bits/stdc++.h>
using namespace std;

double power(double m, int n=2){
	return pow(m, n);
}

int main(){
	int t;	cin >> t;
	while(t--){	
		double m; int n;	cin >> m >> n;	
		cout << power(m, n) << "\n";
	}
	return 0;
}