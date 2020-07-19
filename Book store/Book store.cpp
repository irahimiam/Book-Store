//Book store

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "BOOK.h"


using namespace std;


//fstream f;


class BOOK
{
public:
	int id;
	char name[30];
	char author[30];
	int price;
	int number;
	int stock;
public:
	void getinfo();
	void disinfo();
	void getinfo1(char[], int, int, char[], int);

};

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
		<< setw(15) << author << setw(12) << stock << setw(12) << number << setw(12) << price << endl;
}

void BOOK::getinfo1(char a[30], int b, int c, char d[], int e){
	strcpy(name, a);
	strcpy(author, d);
	id = c;
	number = b;
	price = e;
}

const int size = 100;
BOOK b[size];
void show1();

int main()
{
	int i = 0;
	fstream f1;
	f1.open("book.dat", ios::in | ios::binary);

	while (i < size && f1.eof() != 1){
		f1.read((char *)&b[i], sizeof(b[i]));
		i++;
	}
	f1.close();
	

start:
	std::system("cls");
	cout << "*********************************************************************\n";
	cout << "...............Welcome to the IRAN Book store Services ..............\n";
	cout << "*********************************************************************\n";

	int choice;
	cout << "\tpleas choose ...\n";
	cout << "*********************************************************************\n";
	cout << "\t1. Booking\t\t2. Search\n";
	cout << "\t3. Purchase\t\t4. Update\n";
	cout << "\t5. Store Details\t6. Save & Exit\n";
	cout << "Please Enter your Choice : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
			  char ch;
			  cout << "\t\t------------------------\n";
			  do{
				  b[i].getinfo();
				  cout << "\n\t\tBook Details are \n";
				  cout << "\t\t-----------------------------\n";
				  show1();
				  b[i].disinfo();
				  cout << "\n\n\t..............Booking Successful...............\n";

				  i++;
				  cout << "\nDo you want to continue ?\n";
				  cout << "(Y for yes,N for no)";
				  cin >> ch;
			  } while (ch == 'y' || ch == 'Y');
			  goto start;
	}

		break;
	case 2:
	{
			  int choice;
			  int j = 0;
			  cout << "\tChoose how you want to search the BOOK list\n";
			  cout << "\t1. By Name\n\t2. By Author\n";
			  cout << "Enter your Choice :- ";
			  cin >> choice;

			  switch (choice)
			  {
			  case 1:
			  {

						char sname[30];
						int flag = 0;
						cout << "Enter the BOOK name which you want to search :- ";
						cin >> sname;
						cin.get();

						show1();

						while (j<size)
						{
							if (strcmp(sname, b[j].name) == 0)
							{
								b[j].disinfo();
								cin.get();
								flag = 1;
							}
							j++;
						}

						if (flag == 0)
							cout << "\t!!!!!!Not Found!!!!!!!!\n";

						goto start;
			  }
				  break;

			  case 2:
			  {
						char sauthor[30];
						int flag = 0;
						cout << "Enter the Author Name you want to search :- ";
						cin >> sauthor;
						cin.get();

						show1();

						while (j < size)
						{
							if (strcmp(sauthor, b[j].author) == 0)
							{
								b[j].disinfo();
								cin.get();
								flag = 1;
							}
							j++;
						}

						if (flag == 0)
							cout << "\t\tNot Found !!!\n";

						goto start;

			  }
				  break;
			  }

	}
		break;

	case 3:
	{
			  int flag = 0;
			  int j = 0;
			  //customer info:
			  char sname[30];
			  char sbook[30];
			  cout << "Enter your name:-";
			  cin >> sname;
			  cin.get();
			  

			  char ch;//continue
			  int snumber;//shop number
			  int sum=0;//total shoping
			  int sumprice=0;//total payment

				  cout << "Enter your Book name:-";
				  cin >> sbook;
				  cin.get();

				  show1();

				  while (j < size)
				  {
					  if (strcmp(sbook, b[j].name) == 0)
					  {
						  b[j].disinfo();
						  flag = 1;
						  cout << "\nTotal Fund is:" << b[j].number << endl << endl;

						  do{
							  cout << "Enter number(Enter a valid number):-";
							  cin >> snumber;
							  //cin.get();
						  } while (b[j].number < snumber);
						  cout << "..........Purchase succesful..........\n";

						  sum = sum + snumber;
						  sumprice += snumber*b[j].price;

						  //update stock
						  b[j].number -= snumber;

					  }
					  j++;
				  }

				  if (flag == 0)
					  cout << "\t\tNot Found !!!\n";
				  else{
					  //factor detail
					  std::system("cls");
					  cout << "*********************************************************************\n";
					  cout << ".............................. Factor................................\n";
					  cout << "*********************************************************************\n";
					  //show1();
					  //f.disinfo();
					  cout << "Customer detail...\n";
					  cout << "---------------------------------------------------------------------\n";
					  cout << "Customer name is:" << sname << endl;
					  cout << "Number of shopping is:" << sum << endl;
					  cout << "Your PAYMENT is:" << sumprice << endl;
					  cin.get();
					  cin.get();
				  }
			  
			 goto start;

	}
		break;

	case 4:
	{
			  int id;
			  int flag = 0;
			  int j = 0;
			  cout << "Enter the Book ID which you want to update : ";
			  cin >> id;
			  cin.get();

			  while (j < size){
				  if (id == b[j].id){
					  b[j].getinfo();
					  flag = 1;
				  }
				  j++;
			  }
			  
			  if (flag == 0)
				  cout << "\t\tNot Found !!!\n";
			  cout << "\t\tSuccessfully updated.....\n";
			  cin.get();
			  cin.get();

			  goto start;
	}

	case 5:
	{
			  show1();
			  int j = 0;
			  int sum = 0;

			  while (j < size)
			  {
				  if (b[j].id != 0){
					  b[j].disinfo();
					  sum += b[j].number;
				  }
				  j++;
			  }
			  cout << "\n\tTotal Number of BOOKS is: " << sum << endl;
			  cin.get();
			  cin.get();

			  goto start;

	}
		break;

	case 6:
	{
			  fstream f;
			  remove("book.dat");
			  f.open("book.dat", ios::out | ios::binary | ios::app);
			  int k = 0;

			  while (k < size){
				  if (b[k].id != 0){
					  f.write((char *)&b[k], sizeof(b[k]));
				  }
				  k++;
			  }
			  f.close();
			  exit(0);
	}
		break;
	}

}
/////////////////////////////////////////////////
void show1(){
	cout << endl << left << setw(8) << "ID" << setw(15) << "Name"
		<< setw(15) << "Author" << setw(12) << "Pages" << setw(12) << "Number" << setw(12) << "price" << endl;
	cout << "******************************************************************************" << endl;
}