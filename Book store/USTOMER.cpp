#include "stdafx.h"
#include "USTOMER.h"
#include <iostream>

using namespace std;

void CUSTOMER::getinfo(){
	cout << "Enter your name:-";
	cin.getline(name, 20);

}

void CUSTOMER::disinfo(){
	cout.setf(ios::left);

}