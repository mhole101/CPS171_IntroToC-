//***************************************************************************//
//                                                                           //
//                                 MP8 - Classes                             //
//                                 By: Matt Hole                             //
//                                                                           //
//                                                                           //
//    This program creates a class called book.  This class contains the     //
//    title of the book, the author of the book, and the ISBN of the book.   //
//    The program then has two parts.  The first part will create two book   //
//    objects.  The program then tests the default constructor to make sure  //
//    it works properly on book object 1, and then reads book data from      //
//    input file "mp7book.txt" and places it into the proper members for     //
//    book object 2.  The program then prints out the book information at    //
//    end.  The second part of the program then creates an array with the    //
//    book class,  and places data from an input stream into the proper      //
//    array and member locations.  After this the programs scans another     //
//    input stream that contains ISBN's.  The program searches the array to  //
//    see if it contains matching ISBN's and prints out the book information //
//    if they match.  If not it prints out a message saying "No matching     //
//    books found."                                                          //
//                                                                           //
//                                                                           //
//***************************************************************************//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "book.h"

using namespace std;

void print_data_part_1(book&, book&);


int main()
{
	ifstream inData;
	book book1; // creates first book object for part 1
	book book2; // create second book object for part 1

	inData.open("mp7book.txt"); // opens input stream for part 1

	book2.GetData(inData); // gets data from "mp7book.txt" and places it into book 2 class

	print_data_part_1(book1, book2); // prints data to screen

	inData.close(); // closes input stream for part 1


	return 0;
}

// This function prints out the information for part 1
void print_data_part_1(book& book1, book& book2)
{
	cout << "Testing the book classes\n"
		<< "By: Matt Hole\n\n"
		<< "The information for book 1 is:\n";
	book1.Print();
	cout << "The information for book 2 is:\n";
	book2.Print();
	cout << "book2 has ISBN " << book2.GetISBN() << endl;
	
}