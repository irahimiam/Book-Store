#include "stdafx.h"
#include <iostream>
#include "BOOK.h"
#include <string>
#include <iomanip>

using namespace std;

void BOOK::getinfo(){

	cout << "Enter book id:-";
	cin >> id;

	cout << "Enter book name:-";
	cin.get();
	cin.getline(name, 30);

	cout << "Enter book author:-";
	cin.getline(author, 30);
	
	cout << "Enter stock:-";
	cin >> stock;

	cout << "Enter book price:-";
	cin >> price;

	cout << "Enter number of Books:-";
	cin >> number;
}

void BOOK::disinfo(){
	cout.setf(ios::left);
	cout << endl << left << setw(8) << id << setw(15) << name
		<< setw(15) << author << setw(12) << stock << setw(12)<< number << setw(12) << price << endl;
}

void BOOK::getinfo1(char a[30],int b,int c,char d[],int e){
	strcpy(name, a);
	strcpy(author, d);
	id = c;
	number = b;
	price = e;
}