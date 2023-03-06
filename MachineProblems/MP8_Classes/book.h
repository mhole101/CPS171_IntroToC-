#include<string>
#include<fstream>
#pragma once

using namespace std;

class book
{
public:
	book();
	// default constructor
	// set name to "No name", set title to "No title", and set isbn to 0
	void Print() const;
	// function to print out book information. In the form of:
	// name
	// title
	// isbn
	void GetData(ifstream&);
	// This function gets a input file, and book object as parameters.
	// This function reads information from the file and put appropriate values into the data members.
	long GetISBN() const;
	// This function is used to return the ISBN in long integer format.
	// 
private:
	string name; // variable to store authors name
	string title; // variable to store books title
	long ISBN; // variable to store books ISBN
};

