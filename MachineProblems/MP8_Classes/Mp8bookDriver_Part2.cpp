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

const int numOfLibBooks = 10;
const int numOfBooksToSearch = 9;

void fill_book_array(ifstream&, book[]);
void print_book_array(book[]);
void move_ISBN_to_array(const book[], long[]);
void get_ISBN_to_search(ifstream&, long[]);
int binarySearch(const long[], int, long);
void print_search_results(const book[], long, int);



int main()
{
	ifstream inData;
	book bookArray[10]; // creates book array for part 2
	long libraryISBN[10]; // holds the ISBN for the library books
	long searchISBN[10]; // holds the ISBN for the books to be searched
	int searchPos; // search position for binary search

	cout << "MP8 - Classes Part 2" << endl
		<< "By: Matt Hole" << endl << endl; // Prints title on output
			
	inData.open("mp8bookarray.txt"); // opens input stream for part 2

	fill_book_array(inData, bookArray); // fills book aray with data from "mp8bookarray.txt"

	inData.close(); // closes input stream for book array

	print_book_array(bookArray); // prints books from book array

	move_ISBN_to_array(bookArray, libraryISBN);

	inData.open("mp8bokkISBN.txt"); // opens input stream of books to be searched

	get_ISBN_to_search(inData, searchISBN);

	inData.close(); // closes input stream of books to be searched

	cout << "ISBN Search Results:" << endl << endl; // prints a search header

	for (int i = 0; i < numOfBooksToSearch; i++) // loop to search all ISBN
	{
		searchPos = binarySearch(libraryISBN, numOfLibBooks, searchISBN[i]); // runs binary search and stores position in searchPos

		print_search_results(bookArray, searchISBN[i], searchPos); // prints the search results
	}


	return 0;
}

// This function fills the book array for part 2
void fill_book_array(ifstream& inData, book bookArray[])
{
	for (int i = 0; i < 10; i++)
		bookArray[i].GetData(inData);

}
// This function prints out the books for part 2
void print_book_array(book bookArray[])
{
	cout << "Current books available at the library:" << endl << endl
		<< setw(20) << "Author "
		<< setw(50) << "Title " 
		<< setw(20) << "ISBN" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		bookArray[i].Print();
		cout << endl << endl;
	}
}
// move ISBN from library book member to a long array for searching
void move_ISBN_to_array(const book bookArray[], long libISBN[])
{
	for (int i = 0; i < 10; i++)
		libISBN[i] = bookArray[i].GetISBN();
}
// get ISBN from input stream and store in an array for searcing
void get_ISBN_to_search(ifstream& inData, long searchISBN[])
{
	for (int i = 0; i < 9; i++)
		inData >> searchISBN[i];
}
// binary search used to search for isbn in library
int binarySearch(const long libISBN[], int numOfBooks, long isbnToBeSearched)
{
	int first = 0;
	int last = numOfBooks - 1;
	int mid;
	bool found = false;
	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		if (libISBN[mid] == isbnToBeSearched)
			found = true;
		else if (libISBN[mid] > isbnToBeSearched)
			last = mid - 1;
		else
			first = mid + 1;
	}
	if (found)
		return mid;
	else
		return -1;
}
// this function prints the search results
void print_search_results(const book bookArray[], long searchISBN, int searchPos)
{
	if (searchPos == -1)
		cout << "Sorry, " << searchISBN << " not found." << endl << endl;
	else if (searchPos >= 0 && searchPos <= 9)
	{
		cout << "ISBN: " << searchISBN << " found! " << " Here is the information on your book: " << endl;
		cout << setw(20) << "Author" << setw(50) << "Title" << "ISBN" << endl;
		bookArray[searchPos].Print();
		cout << endl;
	}		
		
}

		