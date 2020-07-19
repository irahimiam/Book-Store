#pragma once
#include <string>
using namespace std;

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
	void getinfo1(char [],int,int,char [],int);

};