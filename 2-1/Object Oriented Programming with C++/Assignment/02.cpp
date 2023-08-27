/*
Write a program to find the largest of three numbers using inline function.
*/
#include<bits/stdc++.h>
using namespace std;

inline int large(int a, int b, int c){
	return max({a, b, c});
}

int main(){
	int a, b, c;	cin >> a >> b >> c;
	cout << large(a, b, c) << "\n";
	
	return 0;
}

