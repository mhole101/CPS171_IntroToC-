//*****************************************************************************//
//                                                                             //
//                                                                             //
//                Machine Problem 6 - Strings and Enumerations                 //
//                                                                             //
//                             By : Matt Hole                                  //
//                                                                             //
//    This program reads an input file.  The first letter on each line is      //
//    to tell us the persons gender.  The next letter is to tell us their      //
//    marital status.  After that is the last name followed directly by a      //
//    comma, then their first name, and if they have one the middle inital     //
//    followed by a period.  The number of spaces between the names are        //
//    random between each name and each line.  This program extracts the data  //
//    processes it and then outputs the original name format followed by the   // 
//    standardized name format.                                                //
//                                                                             //
//                                                                             //
//                                                                             //
//*****************************************************************************//

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>

using namespace std;

enum maritalStatus { SINGLE, MARRIED, DIVORCED };
enum names { PREFIX, FIRST, MIDDLE, LAST };
enum gender {MALE, FEMALE };


maritalStatus marital_status(char);
string get_prefix_string(maritalStatus, char);
string get_line_data(ifstream&, char&, char&, int&);
string build_origial_name(string);
string get_last_name(string&);
string get_first_name(string&);
string get_middle_initial(string&);
string build_standardized_name(string[]);
void store_names_in_array(string[], string[], string&, string&, int);
void output_data(string[], string[], int);


int main()
{
	
	ifstream inData;
	string partsOfName[4];
	string originalNames[50];
	string standardizedNames[50];
	maritalStatus currentNameMaritalStatus;
	names nameCategories;	
	gender currentNameGender;
	string currentLine;
	string originalName;
	string standardizedName;
	char maritalStatusChar;
	char genderChar;
	int numberOfLinesProcessed = 0;
	
	
	inData.open("mp6Names.txt"); // opens input stream

	if (!inData.is_open()) // checks if file opens properly.  Displays message and end program with -1 if not.
	{
		cout << "file did not open" << endl;
		return -1;
	}
		

	while (!inData.eof()) // loop to read, manipulate, and output data until end of file flag.
	{

		currentLine = get_line_data(inData, genderChar, maritalStatusChar, numberOfLinesProcessed); // gets line from input file.
		
		originalName = build_origial_name(currentLine); // creates origial name format.

		currentNameMaritalStatus = marital_status(maritalStatusChar); // checks and sets marital status.
		
		partsOfName[PREFIX] = get_prefix_string(currentNameMaritalStatus, genderChar); // selects proper prefix

		partsOfName[LAST] = get_last_name(currentLine); // finds last name from line and send back to string.

		partsOfName[FIRST] = get_first_name(currentLine); // first name from line and sends back to string.

		partsOfName[MIDDLE] = get_middle_initial(currentLine); // checks for a middle initial, if there it is sent back in a string.
						
		standardizedName = build_standardized_name(partsOfName); // builds name

		store_names_in_array(originalNames, standardizedNames,
			                 originalName, standardizedName, numberOfLinesProcessed); // stores names in array.
				
	}
	
	output_data(standardizedNames, originalNames, numberOfLinesProcessed); // outputs name table.

	

	return 0;

}
// This function is passed an input stream varible, gender char and maritalStatusChar as references.
// The function gets a line from the input and places it into a string.  String functions are used to
// get the gender and maritalStatusChar,  after getting the char that data is erased from the string then 
// the new string is passed back by the function.
string get_line_data(ifstream& inData, char& gender, char& maritalStatusChar, int& numberOfLines)
{
	string lineString;
			
	getline(inData, lineString);
	gender = lineString[0];
	maritalStatusChar = lineString[1];
	lineString = lineString.erase(0, 2);
	numberOfLines++;
	
	return lineString;
}
// This function recieves the current line, creates the original names and sends it back in a string.
string build_origial_name(string currentLine)
{
	string originalName;
	char blankspace = ' ';
	int firstLetterPos;

	firstLetterPos = currentLine.find_first_not_of(blankspace);
	originalName = currentLine.erase(0, firstLetterPos);

	return originalName;
}
// This function is passed the currentLineFirstChar.  It then uses this char to chose the marial status
// and sends it back to an enumeration.
maritalStatus marital_status(char currentLineFirstChar)
{
	maritalStatus currentLineMaritalStatus;
	switch (currentLineFirstChar)
	{
	case 'S':
		currentLineMaritalStatus = SINGLE;
		break;
	case 'M':
		currentLineMaritalStatus = MARRIED;
		break;
	case 'D':
		currentLineMaritalStatus = DIVORCED;
		break;
	}

	return currentLineMaritalStatus;
	
}
// This function is passed the currentLineMaritalStatus, and gender.  It then uses these parameters
// to select the proper prefix.  Prefix is then sent back as a string.
string get_prefix_string(maritalStatus currentLineMaritalStatus, char gender)
{
	string prefixString;

	if (gender == 'F')
	{
		switch (currentLineMaritalStatus)
		{
		case SINGLE:
			prefixString = "Ms.";
			break;
		case MARRIED:
			prefixString = "Mrs.";
			break;
		case DIVORCED:
			prefixString = "Miss";
			break;
		}
	}
	else 
		prefixString = "Mr.";

	return prefixString;

	
}
// This function extracts the last name from the lineString and sends it back in a string.
// After extracting the data it then erases that data out of the lineString.
string get_last_name(string& lineString)
{
	string lastName;
	char comma = ',';
	char blankSpace = ' ';
	int commaPos;
	int firstLetterPos;
	int lastNameLength;

	commaPos = lineString.find(comma);
	firstLetterPos = lineString.find_first_not_of(blankSpace);
	lastNameLength = commaPos - firstLetterPos;
	lastName = lineString.substr(firstLetterPos, lastNameLength);
	lineString = lineString.erase(0, commaPos + 1);

	   	
	return lastName;
}
// This function extracts the first name from the lineString and sends it back in a string.
// After extracting the data it then erases that data out of the lineString.
string get_first_name(string& lineString)
{
	string firstName;
	char blankSpace = ' ';	
	int firstLetterPos;
	int lastLetterPos;
	int firstNameLength;

	
	firstLetterPos = lineString.find_first_not_of(blankSpace);
	lastLetterPos = lineString.find(blankSpace, firstLetterPos);
	firstNameLength = lastLetterPos - firstLetterPos;
	firstName = lineString.substr(firstLetterPos, firstNameLength);
	lineString = lineString.erase(0, firstNameLength + firstLetterPos);
		
	return firstName;
}
// This function searches for a "."  If one is found it extracts the middle
// initial from the string and sends it back in a string.  Clears lineStrig after extractig data.
string get_middle_initial(string& lineString)
{
	string middleInitial = " ";
	char period = '.';
	int periodPos;

	periodPos = lineString.find(period);

	if (periodPos == -1)
	{
		lineString.clear();
		return middleInitial;
	}


	middleInitial = lineString.substr(periodPos - 1, 2);
	lineString.clear();

	return middleInitial;
}
// This function takes a string array and builds a name.  Sends the standardized name back in string.
string build_standardized_name(string partOfName[])
{
	names buildNames;
	string name;
	string blankspace = " ";
	int nameLength;

	for (int i = 0; i < 3; i++)
	{
		partOfName[i] = partOfName[i] + blankspace;
	}

	if (partOfName[MIDDLE] == "  ")
	{
		name = name.insert(0, partOfName[PREFIX]);
		nameLength = name.length();
		name = name.insert(nameLength, partOfName[FIRST]);
		nameLength = name.length();
		name = name.insert(nameLength, partOfName[LAST]);
		return name;
	}
	
	name = name.insert(0, partOfName[PREFIX]);
	nameLength = name.length();
	for (int i = 1; i < 4; i++)
	{
		name = name.insert(nameLength, partOfName[i]);
		nameLength = name.length();
		
	}
	
	return name;
	
}
// This function stores all the processed data in an array to be output later.
void store_names_in_array(string originalNames[], string standardizedNames[], string& originalName, 
	                      string& standardizedName, int numberOfLinesProcessed)
{
	originalNames[numberOfLinesProcessed - 1] = originalName;
	standardizedNames[numberOfLinesProcessed - 1] = standardizedName;
}
// This function outputs the data.
void output_data(string originalNames[], string standardizedNames[], int numberOfLinesProcessed)
{
	cout << "MP6 - Strings and Enumerations\n" << "By: Matt Hole\n\n\n";

	cout << left << setw(30) << "Original name" << "\t" << left << setw(30) << "Standardized name" << endl << endl;
	
	
	for (int i = 0; i < numberOfLinesProcessed; i++)
	{
		cout << left << setw(30) << originalNames[i] << "\t"
			<< left << setw(30) << standardizedNames[i] << endl;
	}
}






