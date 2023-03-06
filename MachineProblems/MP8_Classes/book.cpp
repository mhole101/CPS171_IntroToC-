#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "book.h"

using namespace std;


book::book()
{
	name = "No name";
	title = "Unknown title";
	ISBN = 0;
}

void book::Print() const
{
	cout << left << setw(20) << name  
		<< setw(50) << title 
		<< ISBN << endl;
}

void book::GetData(ifstream& inData)
{
	getline(inData, name);
	getline(inData, title);
	inData >> ISBN;
	inData.ignore(1, '\n'); // this is used to properly
	                        // place data into the class members
	                        // the getline function grabs the blank
	                        // or new line character after the ISBN
}

long book::GetISBN() const
{
	return ISBN;
}
