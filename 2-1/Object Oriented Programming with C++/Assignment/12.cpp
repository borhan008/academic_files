/*
A book shop maintains the inventory of books that are being sold at the shop. The list
includes details such as author, title, price, publisher and stock position. Whenever a
customer wants a book, the sales person inputs the title and author and the system searches
the list and display whether it is available or not. If it is not, an appropriate message is
displayed. If it is, then the system displays the book details and requests for the number of
copies required. If the requested copies are available, the total cost of the requested copies
is displayed; otherwise the message “Required copies not in stock” is displayed.
Write a program using a class called books with suitable member functions and
constructors. Use new operator in constructors to allocate memory space required.

Input:
5
A B 2 3 4 
C D 2 3 4 
E F 2 3 4
G H 2 3 4 
I J 2 3 4 

A B
3
*/

#include<bits/stdc++.h>
using namespace std;

class Books{
	char *title, *author, *publisher;
	float price;
	int stock;
	
	public:
	Books();
	void get();
	bool search(string t, string a);
	void buy();
	void display(){
		cout << title << " " << author << "\n";
	}
};

Books::Books(){
	title = new char[150];
	author = new char[150];
	publisher = new char[150];	
}
void Books::get(){
	cin >> title >> author >> publisher ;
	cin >> price >> stock;
}
bool Books::search(string t, string a){
	if(title == t && a==author){
		cout << "Title : " << title << "\n";
		cout << "Author : " << author << "\n";
		cout << "Publisher : " << publisher << "\n";
		cout << "Price : " << price << "\n";
		cout << "Stock : " << stock << "\n";
		return true;
		
	} else{
		return false;
	}
}
void Books::buy(){
	cout << "Input for required copies << " << "\n";
	int x;	cin >> x;
	
	if(x <= stock){
		cout << x << " copies are available.\n";
		cout << "Total Cost : " << x*price << "\n";
	} else{
		cout << "Required copies not in stock\n";
		return;
	}
}


int main(){
	int n;
	cout << "Total Number of books : \n";
	cin >> n;
	Books books[n];
	for(int i=0; i<n; i++){
		books[i].get();
	}
	
	char *title = new char[150];
	char *author = new char[150];
	
	cin >> title >> author;
	bool found = false;
	for(int i=0; i<n; i++){
		if(books[i].search(title, author)){
			books[i].buy();
			found = true;
			break;
		}
	}
	
	if(!found){
		cout << "Books not found.";
	}
	
}